/* Jonathan Piatos
** CMSI387: Operating System
** chmod.c
** Description: This program demonstrates invocation of the chmod
** system call (15) using the syscall function.  
*/
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/unistd.h>
#include <unistd.h> 
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int result = syscall(15, argv[1], 00004);

  if (result == 0) {
    // Don't use this error message in "real" programs. O_o
    char *successMessage = "Read Access is Changed\n";
    syscall(4, 2, successMessage, strlen(successMessage));
  } else if(result == -1) {

    char *errorMessage = "Read Access could not be changed\n";
    syscall(4, 2, errorMessage, strlen(errorMessage));

  }

}
