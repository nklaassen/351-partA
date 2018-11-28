#include <linux/syscalls.h>
#include <asm-generic/uaccess.h>

SYSCALL_DEFINE1(strlen, char const*, str)
{
	// strnlen_user returns the length of the string, including the null terminator
	long strlen = strnlen_user(str, 32767);

	// strnlen_user returns 0 on error
	if (strlen < 1)
	{
		return -2;
	}

	// get the length of the string without the null terminator
	strlen--;

	// print a message including the string length to the kernel logs
	printk(KERN_INFO "strlen syscall, string length is %ld.\n", strlen);
	return 0;
}
