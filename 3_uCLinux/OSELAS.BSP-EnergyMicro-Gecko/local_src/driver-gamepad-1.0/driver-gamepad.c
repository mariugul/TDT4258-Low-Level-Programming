/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *             Gamepad Driver Module                     *
 *                                                       *
 *  This is a demo Linux kernel module.					 *
 *	miniterm.py -b 115200 -p /dev/ttyUSB0			     * 
 *	modprobe driver-gamepad								 *
 *														 *
 * By: Marius C. K. Gulbrandsen 						 *
 *     Antoni Munes										 *
 *     Andrea ... 								         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


// Includes
//---------------------------------------------------
#include "efm32gg.h"
#include "driver-gamepad.h"
#include <asm/io.h>
#include <asm/siginfo.h>
#include <asm/signal.h>
#include <asm/uaccess.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/ioport.h>
#include <linux/kdev_t.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

// Definitions
//---------------------------------------------------


// Variables
//---------------------------------------------------
static dev_t device_nr;
dev_t devno;
struct cdev gamepad_cdev;
struct class* cl;
struct fasync_struct* async_queue;

// Typedefs
//---------------------------------------------------
static struct file_operations gamepad_flops = {
    .owner = THIS_MODULE,
    .read = gamepad_read,
    .write = gamepad_write,
    .open = gamepad_open,
    .release = gamepad_release
};


// Function Definitions
//---------------------------------------------------
//Returns 0 if successfull, otherwise -1

// Set input and output pins
void gpio_set_pins(void)
{
    *GPIO_PA_MODEH = 0x55555555; // Set pins A8-15 as output
    *GPIO_PC_MODEL = 0x33333333; // Set pins C0-7 as input
    *GPIO_PC_DOUT = 0xFF; // Enable internal pull-up
}

void gpio_enable_interrupt()
{
    *GPIO_EXTIPSELL = 0x22222222;
    *GPIO_EXTIFALL = 0xFF; // Interrupt on falling edge
    *GPIO_EXTIRISE = 0xFF; // Interrupt on rising edge
    *GPIO_IEN = 0x00FF; // Interrupt enable
    *GPIO_IFC = 0xFF; // Clear interrupt flag
}

void gpio_init(void)
{
    printk("point3");
    gpio_set_pins();
    printk("point5\n");
    gpio_enable_interrupt();
}

static int gamepad_open(struct inode* inode, struct file* flip)
{
    printk("Hey, gamepad_open has been executed!\n");
    gpio_init();
    printk("GPIO pins initialized...\n");
    return 0;
}

static int gamepad_release(struct inode* inode, struct file* flip)
{
    unsigned long n = 0x24;
    //release_mem_region(GPIO_PA_BASE ,n);
    //release_mem_region(GPIO_PC_BASE ,n);

    printk("Hey, gamepad_release has been executed!\n");

    //cdev_del(&gamepad_cdev); //No return paramater
    return 0;
}

static ssize_t gamepad_read(struct file* flip, char __user* buff, size_t count, loff_t* offp)
{
    unsigned long copyRet;
    //Copy to buff one byte from READ_BUTTONS address
    copyRet = copy_to_user(buff, GPIO_PC_DIN, 2);
    //printk("Copied value Buf: %x\n",*buff);

    return 0;
}

static ssize_t gamepad_write(struct file* flip, char __user* buff, size_t count, loff_t* offp)
{
    printk("Hey, gamepad_write has been executed!\n");
    return 0;
}


static int __init gamepad_init(void)
{
    int res_alloc;
    int resultPortA;
    int resultPortC;
    struct device* chrdev;

    // Allocate device number
    if (alloc_chrdev_region(&device_nr, 0, DEV_NR_COUNT, DRIVER_NAME)) {
        printk(KERN_ALERT "Failed to allocate device numbers\n");
        return -1;
    }

    // Request memory
    if (request_mem_region(GPIO_PC_MODEL, 1, DRIVER_NAME) == NULL ) {
        printk(KERN_ALERT "Error requesting GPIO_PC_MODEL memory region.\n");
        return -1;
    }
    if (request_mem_region(GPIO_PC_DOUT, 1, DRIVER_NAME) == NULL ) {
        printk(KERN_ALERT "Error requesting GPIO_PC_DOUT memory region.\n");
        return -1;
    }
    if (request_mem_region(GPIO_PC_DIN, 1, DRIVER_NAME) == NULL ) {
        printk(KERN_ALERT "Error requesting GPIO_PC_DIN memory region.\n");
        return -1;
    }
   
    //Request memory region
    /* DO WE NEED THIS?
    resultPortA = (int)request_mem_region((int)GPIO_PA_BASE, 0x24, "gamePad");
    resultPortC = (int)request_mem_region((int)GPIO_PC_BASE, 0x24, "gamePad");

    printk("Executing gamepad_init:\n");
    printk("Region requested with codes: %d, %d\n", resultPortA, resultPortC);
	
    res_alloc = alloc_chrdev_region(&devno, 0, 1, "gamePaad");
    printk("alloc_chrdev_region executed with %d code.\n", res_alloc);
    */

    gamepad_cdev = cdev_alloc();
    gamepad_cdev.ops = &gamepad_flops;
    cdev_init(&gamepad_cdev, &gamepad_flops);
    int ret_cdev_add = cdev_add(&gamepad_cdev, devno, 1); //not sure about the 0, is the first device number to wich this device responds

    printk("devno = %d, cdev_add terminedd with:%d \n", (int)devno, ret_cdev_add);

    cl = class_create(THIS_MODULE, "gamePad");
    chrdev = device_create(cl, NULL, devno, NULL, "gamePad");
    if (IS_ERR(chrdev)) {
        printk("error in device_create");
    }


    iowrite32(0x33333333, GPIO_PC_MODEL);
    iowrite32(0xFF, GPIO_PC_DOUT);
    iowrite32(0x22222222, GPIO_EXTIPSELL);

    // Request interrupt from odd and even GPIO pins
    request_irq(GPIO_EVEN_IRQ_LINE, (irq_handler_t)gpio_interrupt_handler, 0, DRIVER_NAME, &gamepad_cdev);
    request_irq(GPIO_ODD_IRQ_LINE, (irq_handler_t)gpio_interrupt_handler, 0, DRIVER_NAME, &gamepad_cdev);

    /* add device */
    cdev_init(&gamepad_cdev, &gamepad_fops);
    gamepad_cdev.owner = THIS_MODULE;
    cdev_add(&gamepad_cdev, device_nr, DEV_NR_COUNT);
    cl = class_create(THIS_MODULE, DRIVER_NAME);
    device_create(cl, NULL, device_nr, NULL, DRIVER_NAME);

    // Enable interrupts
    iowrite32(0xFF, GPIO_EXTIFALL);
    iowrite32(0x00FF, GPIO_IEN);
    iowrite32(0xFF, GPIO_IFC);

    printk("Class creted\n");
    return 0;

}

/*
 * cleanup - function to cleanup this module from kernel space
 *
 * This is the second of two exported functions to handle cleanup this
 * code from a running kernel
 */

static void __exit gamepad_cleanup(void)
{
    printk("Short life for a small module...\n");
}

module_init(gamepad_init);
module_exit(gamepad_cleanup);

MODULE_DESCRIPTION("Gamepad device driver for tdt4258.");
MODULE_LICENSE("GPL");



static int gamepad_fasync(int fd, struct file* filp, int mode) 
{
    return fasync_helper(fd, filp, mode, &async_queue);
}


// Interrupt Handler
//---------------------------------------------------
irqreturn_t gpio_interrupt_handler(int irq, void* dev_id, struct pt_regs* regs)
{
    printk(KERN_ALERT "GPIO interrupt handler\n");
    iowrite32(ioread32(GPIO_IF), GPIO_IFC);
    if (async_queue) {
        kill_fasync(&async_queue, SIGIO, POLL_IN);
    }
    return IRQ_HANDLED;
}

