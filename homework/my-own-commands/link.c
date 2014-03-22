/* 
**
** CMSI387: Operating System
** link.c
**
** Description: This program demonstrates invocation of the link
** system call (9) using the syscall function.
**
** Contributions made by Abdul Alzaid, Carlos Agudo, and Jonathan Piatos
**
*/

#include <linux/types.h>
#include <linux/unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    int result = syscall(9, argv[1], argv[2]);
    
    if (result == -1) {
        char *errorMessage = "The file unsuccessfully linked to the name\n";
        syscall(4, 2, errorMessage, strlen(errorMessage));
    } else if (result == 0) {
        char *completionMessage = "The file successfully linked to the name\n";
        syscall(4, 2, completionMessage, strlen(completionMessage));
    }
}