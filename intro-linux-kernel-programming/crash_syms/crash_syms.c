#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>  // for "jiffies" variable

static int __init syms_in(void)
{
    printk(KERN_INFO "module crash_syms being loaded.\n");
    printk("Current jiffies: %lu.\n", jiffies);
    return 0;
}

static void __exit syms_out(void)
{
    printk(KERN_INFO "module crash_syms being unloaded.\n");
}

module_init(syms_in);
module_exit(syms_out);

MODULE_AUTHOR("Robert P. J. Day, http://crashcourse.ca");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Symbols, exported and otherwise.");