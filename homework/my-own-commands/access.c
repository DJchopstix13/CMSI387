/* Jonathan Piatos
** CMSI387: Operating System
** access.c
** Description: TThis program demonstrates invocation of the Access
 * system call (33) using the syscall function.
 */
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/unistd.h>
#include <unistd.h> 
#include <stdio.h>

int main(int argc, char *argv[]) {

    int result = syscall(33, argv[1], R_OK);

    if (result == 0) {
    	//message used simply for testing the syscall
        char *successMessage = "Read Access is Granted\n";
        syscall(4, 2, successMessage, strlen(successMessage));
    }
}