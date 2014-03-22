/* 
** 
** CMSI387: Operating System
** symlink.c
** 
** Description: This program implements the 
** symlink system call (83) using the syscall function.
** 
** Contributions made by Abdul Alzaid, Carlos Agudo, and Jonathan Piatos
**
*/

#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	int result = syscall(83, argv[1], argv[2]);

	if (result == 0) {
		char *successMessage = "Successfully created a symbolic link to the file.\n ";
		syscall(4, 2, successMessage, strlen(successMessage));
	} else if (result == -1) {
		char *errorMessage = "Unsuccessfully created a symbolic link to the file. First input must be a file.";
		syscall(4, 2, errorMessage, strlen(errorMessage));
	}
}