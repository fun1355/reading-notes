/* Module source file 'crash1.c'. */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

static int hi(void)
{
     printk(KERN_INFO "crash1 module being loaded.\n");
     return 0;
}

static void bye(void)
{
     printk(KERN_INFO "crash1 module being unloaded.\n");
}

module_init(hi);
module_exit(bye);

MODULE_AUTHOR("Robert P. J. Day, http://crashcourse.ca");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("Doing a whole lot of nothing.");