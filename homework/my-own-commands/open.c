/**
 * This program demonstrates invocation of the sysinfo
 * system call (116) using the syscall function.  Some
 * of its output is then displayed.
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
    // Don't use this error message in "real" programs. O_o
    printf("Opened file with user permision Descriptor %d\n", result);
//    syscall(4, 2, successMessage, strlen(successMessage));
  } else if (result == -1){

  	char *errorMessage = "Could not open file\n";
    syscall(4, 2, errorMessage, strlen(errorMessage));

  }

}
