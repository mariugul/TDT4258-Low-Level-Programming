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
#include "efm32gg.h"

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
	gpio_enable_clock();
    gpio_set_drive(0x00);
    gpio_set_pins();
    gpio_leds_off();
    //gpio_enable_interrupt();
}

static int my_open(struct inode *inode, struct file *flip){
	printk("Hey, my_open has been executed!");
	gpio_init();
	printk("GPIO pins initialized...");
	return 0;
}

static int my_release(struct inode *inode, struct file *flip){
	unsigned long n = 0x24;
	release_region(GPIO_PA_BASE ,n);
	release_region(GPIO_PC_BASE ,n);
	release_region(CMU_HFCORECLKEN0 ,0x4);
	printk("Hey, my_release has been executed!");
	printk("Region released");
	return 0;
}

static ssize_t my_read(struct file *flip, char __user *buff, size_t count, loff_t *offp){
	printk("Hey, my_read has been executed!");
	//Copy to buff one byte from READ_BUTTONS address 
	copy_to_user(buff,*READ_BUTTONS,1);
	return 0;
}

static ssize_t my_write(struct file *flip, char __user *buff, size_t count, loff_t *offp){
	printk("Hey, my_write has been executed!");
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
	
	//Here we will  reserve space for the ports
	//cdev_add();
	//unsigned long n = 0x24;
	//0x24 = 36 en decimal
	int resultPortA = request_region(GPIO_PA_BASE ,36,"gamePad");
	int resultPortC = request_region(GPIO_PC_BASE ,36,"gamePad");
	int resultCoreClk = request_region(CMU_HFCORECLKEN0 ,4,"gamePad");
	printk("Hello World, here is your module speaking!!!! :)\n");
	
	printk("Region requested with codes: %d, %d, %d",resultPortA,resultPortC,resultCoreClk);
	struct cdev *my_cdev = cdev_alloc();
	my_cdev->ops = &my_flops;
	cdev_init(my_cdev,&my_flops);

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

