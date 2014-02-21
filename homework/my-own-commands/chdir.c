/* 
** 
** CMSI387: Operating System
** chdir.c
** 
** Description: This program implements the 
** chdir system call (12) using the syscall function.
** 
** Contributions made by Abdul Alzaid, Carlos Agudo, and Jonathan Piatos
**
*/

#include <linux/types.h>
#include <linux/unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  
    int result = syscall(12, argv[1], 0777);
    char *errorMessage =  "not possible\n";
    char *successMessage = "you changed directories\n";
    if (result == -1) {
        syscall(4, 2, errorMessage, strlen(errorMessage));
    } else if (result == 0) {
        syscall(4, 2, successMessage, strlen(successMessage));
    }
}
