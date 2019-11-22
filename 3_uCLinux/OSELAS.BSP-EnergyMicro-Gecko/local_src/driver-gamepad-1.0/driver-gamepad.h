/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *             Gamepad Driver Module                     *
 *                                                       *
 *  This is a demo Linux kernel module.                  *
 *  miniterm.py -b 115200 -p /dev/ttyUSB0                * 
 *  modprobe driver-gamepad                              *
 *                                                       *
 * By: Marius C. K. Gulbrandsen                          *
 *     Antoni Munes                                      *
 *     Andrea ...                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Header Guard
//---------------------------------------------------
#ifndef __DRIVER - GAMEPAD_H__
#define __DRIVER -GAMEPAD_H__

// Includes
//---------------------------------------------------

// Definitions
//---------------------------------------------------
#define DRIVER_NAME "gamepad"
#define DEV_NUM 1
#define GPIO_IRQ_EVEN 17
#define GPIO_IRQ_ODD 18

// Variables
//---------------------------------------------------

// Typedefs
//---------------------------------------------------

// Function Definitions
//---------------------------------------------------
void gpio_set_pins(void);
void gpio_enable_interrupt();
void gpio_init(void);

/* I'm not sure if we can have these prototypes in a .h file like this. Ask the teacher?
 * If we can, I think it's good practce to declare them here in the .h file.
 */
static int __init gamepad_init(void);
static void __exit gamepad_cleanup(void);
static int gamepad_fasync(int fd, struct file* filp, int mode);
static int gamepad_open(struct inode* inode, struct file* flip);
static int gamepad_release(struct inode* inode, struct file* flip);
static ssize_t gamepad_read(struct file* flip, char __user* buff, size_t count, loff_t* offp);
static ssize_t gamepad_write(struct file* flip, char __user* buff, size_t count, loff_t* offp);

// Interrupt Handler
//---------------------------------------------------
irqreturn_t gpio_interrupt_handler(int irq, void* dev_id, struct pt_regs* regs);

#endif