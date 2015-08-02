/* Module source file 'crash4.c'. */

#include <linux/module.h>   // for all modules
#include <linux/moduleparam.h>    // This is new for parameters.
#include <linux/init.h>     // for entry/exit macros
#include <linux/kernel.h>   // for printk() definition

static int answer = 42;
/* module_param(answer, int, 0644); */
module_param_named(crash4_answer, answer, int, 0644);
MODULE_PARM_DESC(crash4_answer, "Life, the universe, etc.");

static int __init crash4_hi(void)
{
    printk(KERN_INFO "crash4 module being loaded.\n");
    printk(KERN_INFO "Initial value of answer = %d.\n", answer);
    return 0;
}

static void __exit crash4_bye(void)
{
    printk(KERN_INFO "crash4 module being unloaded.\n");
    printk(KERN_INFO "Final value of answer = %d.\n", answer);
}

module_init(crash4_hi);
module_exit(crash4_bye);

MODULE_AUTHOR("Robert P. J. Day, http://crashcourse.ca");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Testing module parameters.");