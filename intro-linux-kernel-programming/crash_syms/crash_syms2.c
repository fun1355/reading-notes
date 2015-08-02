#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

static int crash_syms2_static;
int        crash_syms2_external;
int        crash_syms2_exported;

EXPORT_SYMBOL(crash_syms2_exported);

static int __init syms_in(void)
{
    printk(KERN_INFO "module crash_syms2 being loaded.\n");
    return 0;
}

static void __exit syms_out(void)
{
    printk(KERN_INFO "module crash_syms2 being unloaded.\n");
}

module_init(syms_in);
module_exit(syms_out);

MODULE_AUTHOR("Robert P. J. Day, http://crashcourse.ca");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Exporting some of our own symbols.");