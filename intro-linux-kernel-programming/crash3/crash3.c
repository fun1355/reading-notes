/* Module source file 'crash3.c'. */

#include <linux/module.h>   // for all modules
#include <linux/init.h>     // for entry/exit macros
#include <linux/kernel.h>   // for printk() definition
#include <asm/current.h>    // process information
#include <linux/sched.h>    // for task_struct definition

static int __init hi(void)
{
     printk(KERN_DEBUG "crash3 module being loaded.\n");
     printk(KERN_DEBUG "User space process is '%s'\n", current->comm);
     printk(KERN_DEBUG "User space PID is  %i\n", current->pid);
     return 0;
}

/* static void __exit bye(void) */
/* { */
/*     printk(KERN_DEBUG "crash3 module being unloaded.\n"); */
/* } */

module_init(hi);
/* module_exit(bye); */

MODULE_AUTHOR("Robert P. J. Day, http://crashcourse.ca");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Doing a whole lot of nothing.");