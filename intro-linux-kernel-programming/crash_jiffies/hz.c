#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

static int
hz_show(struct seq_file *m, void *v)
{
    seq_printf(m, "%d\n", HZ);
    return 0;
}

static int
hz_open(struct inode *inode, struct file *file)
{
    return single_open(file, hz_show, NULL);
}

static const struct file_operations hz_fops = {
    .owner      = THIS_MODULE,
    .open       = hz_open,
    .read       = seq_read,
    .llseek     = seq_lseek,
    .release    = single_release,
};

static int __init
hz_init(void)
{
    printk(KERN_INFO "Loading hz module, HZ = %d.\n", HZ);
    proc_create("hz", 0677, NULL, &hz_fops);
    return 0;
}

static void __exit
hz_exit(void)
{
    remove_proc_entry("hz", NULL);
    printk(KERN_INFO "Unloading hz module.\n");
}

module_init(hz_init);
module_exit(hz_exit);

MODULE_LICENSE("GPL");