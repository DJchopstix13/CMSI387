/*
** 
** CMSI387: Operating System
** rmdir.c 
**
** This program demonstrates invocation of the rmdir system call
** (40) using the syscall function.  Some of its output is then displayed.
**
** Contributions made by Abdul Alzaid, Carlos Agudo, and Jonathan Piatos
**
*/

#include <linux/types.h>
#include <linux/unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  
    int result = syscall(40, argv[1]);

    if (result == 0) {
        char *successMessage = "Directory Removed Successfully\n";
        syscall(4, 2, successMessage, strlen(successMessage));
    } 

    if (result == -1) {
        char *errorMessage = "Directory Removed Unsuccessfully\n";
        syscall(4, 2, errorMessage, strlen(errorMessage));
    }

}
