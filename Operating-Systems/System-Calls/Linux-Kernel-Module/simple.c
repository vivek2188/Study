// lsmod: List all kernel modules that are currently loaded.
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/list.h>
#include <linux/slab.h>

// Refer to: https://github.com/torvalds/linux/blob/master/include/linux/list.h for getting more info. on circular list implementation.

// Birthday structure
struct birthday{
	int day;	
	int month;
	int year;
	struct list_head *list; // It's circular linked list and list_head is defined in #include <linux/types.h>
};

// List consisting all birthday data
struct birthday birthdayList;

// Module Entry Point - Function is invoked when the module is loaded into kernel
int simple_init(void){
	printk(KERN_INFO "Loading the module\n");
	// Declaring the variables
	struct birthday *person, *birthdayVar;
	// Defining birthdayList
	INIT_LIST_HEAD(birthdayList.list);
	return 0;	// 0 represents success and rest indicates failure
}
/*
	printk: It is kernel equivalent of printf and its output is sent to 
		kernel log buffer whose content can be accessed via dmesg
		command. It allows us to specify a priority flag whose 
		values are given in #include <linux/printk.h> file.
		KERN_INFO: Informational Message
*/
// Module exit point - Function is invoked when the module is removed from the kernel
void simple_exit(void){
	printk(KERN_INFO "Removing Module\n");
	// return type must be void
}

// Macros for registering the module entry and exit point
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

/*
	Helpful commands: 
		1. Kernel modules are loaded using insmod command
			sudo insmod simple.ko
		2. Kernel modules are removed using rmmod command
			sudo rmmod simple	// no need of .ko extension
		3. You can check to the message it writes in the kernel log buffer by dmesg command
*/
