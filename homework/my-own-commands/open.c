/*
** 
** CMSI387: Operating System
** chmod.c 
**
** This program demonstrates invocation of the sysinfo system call
** (116) using the syscall function.  Some of its output is then displayed.
**
** Contributions made by Abdul Alzaid, Carlos Agudo, and Jonathan Piatos
**
*/

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/stat.h> 
#include <fcntl.h> 
#include <linux/unistd.h>
#include <unistd.h> 
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

	int result = syscall(5, argv[1], O_RDONLY, 00400);

	if (result > 0) {
		printf("Opened file with user permision Descriptor %d\n", result);
	} else if (result == -1){
		char *errorMessage = "Could not open file\n";
		syscall(4, 2, errorMessage, strlen(errorMessage));
	}

}
