#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

// Module Entry Point - Function is invoked when the module is loaded into kernel
int simple_init(void){
	printk(KERN_INFO "Loading Module\n");	
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
