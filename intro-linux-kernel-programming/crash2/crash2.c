/* Module source file 'crash2.c'. */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

static int __init hi(void)
{
     printk(KERN_INFO "crash2 module being loaded.\n");
     return 0;
}
//return -8: insmod: ERROR: could not insert module crash2.ko: Invalid module format
//return -7:insmod: ERROR: could not insert module crash2.ko: Argument list too long

static void __exit bye(void)
{
     printk(KERN_INFO "crash2 module being unloaded.\n");
}

module_init(hi);
module_exit(bye);

MODULE_AUTHOR("Robert P. J. Day, http://crashcourse.ca");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Doing a whole lot of nothing.");
