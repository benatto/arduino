#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>
#include <linux/fs.h>

#define DRIVER_AUTHOR "Marco A Benatto <benatto@mandriva.com.br>"
#define DRIVER_DESC "Hello World driver!"

static short int myshort = 1;
static int myint = 420;
static char *mystring = "blah";


module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
module_param(mystring, charp, 0000);


static int __init init(void){
	printk(KERN_INFO "Hello world 1.\n");

	printk(KERN_INFO "Hi: %s, your short is: %hd and your integer is %d\n", mystring, myshort, myint);

	return 0;
}

static void __exit cleanup(void){
	printk(KERN_INFO "Goodbye world 1.\n");
}

module_init(init);
module_exit(cleanup);

MODULE_LICENSE("GPL");

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);

MODULE_SUPPORTED_DEVICE("testdriver");
