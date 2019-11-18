/*
 * This is a demo Linux kernel module.
 miniterm.py -b 115200 -p /dev/ttyUSB0
 modprobe driver-gamepad

 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/ioport.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/err.h>
#include "efm32gg.h"

//Global variables:
dev_t devno;
struct cdev my_cdev;
struct class *cl;

/*
 * template_init - function to insert this module into kernel space
 *
 * This is the first of two exported functions to handle inserting this
 * code into a running kernel
 *
 * Returns 0 if successfull, otherwise -1
 */
/** Enable the GPIO clock */


//Enable gpio clock
void gpio_enable_clock(void)
{
    *CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_GPIO; // Enable GPIO clock
}

//Set the drive strength for the leds 
void gpio_set_drive(int drive)
{
    *GPIO_PA_CTRL = drive; // Set high drive strength
}

// Set input and output pins 
void gpio_set_pins(void)
{
    *GPIO_PA_MODEH = 0x55555555; // Set pins A8-15 as output
    *GPIO_PC_MODEL = 0x33333333; // Set pins C0-7 as input
    *GPIO_PC_DOUT = 0xFF; // Enable internal pull-up
}

void gpio_leds_off(void)
{
    *GPIO_PA_DOUT = 0xFF00; // Turns leds off
}

void gpio_init(void)
{
	printk("point1");
	gpio_enable_clock();
	printk("point2");
    gpio_set_drive(0x00);
    printk("point3");
    gpio_set_pins();
    printk("point4");
    gpio_leds_off();
    printk("point5\n");
    //gpio_enable_interrupt();
}

static int my_open(struct inode *inode, struct file *flip){
	printk("Hey, my_open has been executed!\n");
	gpio_init();
	printk("GPIO pins initialized...\n");
	return 0;
}

static int my_release(struct inode *inode, struct file *flip){
	unsigned long n = 0x24;
	//release_mem_region(GPIO_PA_BASE ,n);
	//release_mem_region(GPIO_PC_BASE ,n);

	printk("Hey, my_release has been executed!\n");

	//cdev_del(&my_cdev); //No return paramater
	return 0;
}

static ssize_t my_read(struct file *flip, char __user *buff, size_t count, loff_t *offp){
	unsigned long copyRet;
	//Copy to buff one byte from READ_BUTTONS address 
	copyRet = copy_to_user(buff, GPIO_PC_DIN,2);
	//printk("Copied value Buf: %x\n",*buff);

	return 0;
}

static ssize_t my_write(struct file *flip, char __user *buff, size_t count, loff_t *offp){
	printk("Hey, my_write has been executed!\n");
	return 0;
}

static struct file_operations my_flops = {
	.owner = THIS_MODULE,
	.read = my_read,
	.write = my_write,
	.open = my_open,
	.release = my_release
};


static int __init my_init(void)
{
	int res_alloc;
	int resultPortA;
	int resultPortC;
	struct device *chrdev;
	//Request memory region
	resultPortA = (int)request_mem_region((int)GPIO_PA_BASE ,0x24,"gamePad");
	resultPortC = (int)request_mem_region((int)GPIO_PC_BASE ,0x24,"gamePad");

	printk("Executing my_init:\n");
	printk("Region requested with codes: %d, %d\n",resultPortA,resultPortC);

	res_alloc = alloc_chrdev_region(&devno,0,1,"gamePaad");
	printk("alloc_chrdev_region executed with %d code.\n",res_alloc);

	//my_cdev = cdev_alloc();
	my_cdev.ops = &my_flops;
	cdev_init(&my_cdev,&my_flops);
	int ret_cdev_add = cdev_add(&my_cdev, devno, 1); //not sure about the 0, is the first device number to wich this device responds

	printk("devno = %d, cdev_add terminedd with:%d \n",(int)devno,ret_cdev_add);

	
	cl = class_create(THIS_MODULE, "gamePad");
	chrdev = device_create(cl, NULL, devno, NULL, "gamePad");
	if(IS_ERR(chrdev)){
		printk("error in device_create");
	}

	printk("Class creted\n");
	return 0;
}

/*
 * template_cleanup - function to cleanup this module from kernel space
 *
 * This is the second of two exported functions to handle cleanup this
 * code from a running kernel
 */

static void __exit my_cleanup(void)
{
	 printk("Short life for a small module...\n");
}

module_init(my_init);
module_exit(my_cleanup);

MODULE_DESCRIPTION("Small module, demo only, not very useful.");
MODULE_LICENSE("GPL");

