#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/unacess.h>

#define NAME mychardevice

int NAME_open(struct inode *inode,struct file *filp);

int NAME_release(struct inode *inode,struct file *filp);

ssize_t NAME_write(struct file *filp,const char_user *buff,size_t count,loff_t *offp);

struct file_operation fops=
{
  .owner=THIS_MODULE,
  .open=NAME_open,
  .write=NAME_write,
  .release=NAME_release,
}

struct cdev *my_cdev;

static int chardevice_init(void)
{
int result;
int MAJOR,MINOR;
dev_t Mydev;
Mydev=MKDEV(255,0);
MAJOR=MAJOR(Mydev);
MINOR=MINOR(Mydev);
printk("maj num is:%d,minor num is:%d",MAJOR,MINOR);
result=register_chrdev_region(Mydev,2,mychardevice);
if(result<0)
{
printk(KERN_ALERT "CHAR DEVICE")
return (-1);
}
result=cdev_add(my cdev,Mydev,2);
if(result<0)
{
printk(KERN_ALERT "DEVICE HAS NOT CREATED");
unregister_chrdev_region(Mydev,2);
return (-1);
}
return 0;
}
static void chardevice_exit(void)
{
dev_t Mydev;
int MAJOR,MINOR;
MKDEV=MKDEV(255,0);
MAJOR=MAJOR(Mydev);
MINOR=MINOR(Mydev);
printk("major no. is:%d--minor no is:%d",MAJOR,MINOR);
unregister_chrdev_region(Mydev,2);
cdev_del(my_cdev);
return;
}


