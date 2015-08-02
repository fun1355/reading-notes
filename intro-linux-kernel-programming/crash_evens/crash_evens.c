#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/slab.h>      // for kmalloc() dynamic allocation

static int limit = 10;
module_param(limit, int, S_IRUGO);

static int* even_ptr;

static void *
ct_seq_start(struct seq_file *s, loff_t *pos)
{
    printk(KERN_INFO "Entering start(), pos = %Ld.\n", *pos);

    if ((*pos) >= limit) {     // are we done?
        printk(KERN_INFO "Apparently, we're done.\n");
        return NULL;
    }

    //  Allocate an integer to hold our increasing even value.

    even_ptr = kmalloc(sizeof(int), GFP_KERNEL);

    if (!even_ptr)     // fatal kernel allocation error
        return NULL;

    printk(KERN_INFO "In start(), even_ptr = %pX.\n", even_ptr);
    *even_ptr = (*pos) * 2;
    return even_ptr;
}

static int
ct_seq_show(struct seq_file *s, void *v)
{
    printk(KERN_INFO "In show(), even = %d.\n", *((int*)v));
    seq_printf(s, "The current value of the even number is %d\n",
        *((int*)v));
    return 0;
}

static void *
ct_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
    int* val_ptr;

    printk(KERN_INFO "In next(), v = %pX, pos = %Ld.\n", v, *pos);

    (*pos)++;                // increase my position counter
    if ((*pos) >= limit)     // are we done?
         return NULL;

    val_ptr = (int *) v;     // address of current even value
    (*val_ptr) += 2;         // increase it by two

    return v;
}

static void
ct_seq_stop(struct seq_file *s, void *v)
{
    printk(KERN_INFO "Entering stop().\n");

    if (v) {
        printk(KERN_INFO "v is %pX.\n", v);
    } else {
        printk(KERN_INFO "v is null.\n");
    }

    printk(KERN_INFO "In stop(), even_ptr = %pX.\n", even_ptr);

    if (even_ptr) {
        printk(KERN_INFO "Freeing and clearing even_ptr.\n");
        kfree(even_ptr);
        even_ptr = NULL;
    } else {
        printk(KERN_INFO "even_ptr is already null.\n");
    }
}

static struct seq_operations ct_seq_ops = {
    .start = ct_seq_start,
    .next  = ct_seq_next,
    .stop  = ct_seq_stop,
    .show  = ct_seq_show
};

static int
ct_open(struct inode *inode, struct file *file)
{
    return seq_open(file, &ct_seq_ops);
};

static struct file_operations ct_file_ops = {
    .owner   = THIS_MODULE,
    .open    = ct_open,
    .read    = seq_read,
    .llseek  = seq_lseek,
    .release = seq_release
};

static int
ct_init(void)
{
    proc_create("evens", 0, NULL, &ct_file_ops);
    return 0;
}

static void
ct_exit(void)
{
    remove_proc_entry("evens", NULL);
}

module_init(ct_init);
module_exit(ct_exit);

MODULE_LICENSE("GPL");