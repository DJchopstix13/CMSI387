/* 
** 
** CMSI387: Operating System
** access.c
**
** Description: TThis program demonstrates invocation of the access 
** system call (33) using the syscall function.
**
** Contributions made by Abdul Alzaid, Carlos Agudo, and Jonathan Piatos
**
*/

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/unistd.h>
#include <unistd.h> 
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    //Only check access for read only
    int result = syscall(33, argv[1], R_OK);

    if (result == 0) {

        char *successMessage = "User Access Available\n";
        syscall(4, 2, successMessage, strlen(successMessage));
    } else if (result == -1) {
        char *failureMessage = "User Access Unavailable\n";
        syscall(4, 2, failureMessage, strlen(failureMessage));
    }

}