/* 
** 
** CMSI387: Operating System
** rename.c
**
** Description: This program demonstrates invocation of the rename
** system call (38) using the syscall function.
**
** Contributions made by Abdul Alzaid, Carlos Agudo, and Jonathan Piatos
**
*/

#include <linux/types.h>
#include <linux/unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int result = syscall(38, argv[1], argv[2]);
    
    //messages are used to see if syscall worked or not
    if (result == -1) {
        char *errorMessage = "This renaming is wrong\n";
        syscall(4, 2, errorMessage, strlen(errorMessage));
    } else if (result == 0) {
        char *completionMessage = "This renaming is right\n";
        syscall(4, 2, completionMessage, strlen(completionMessage));
    }

}
