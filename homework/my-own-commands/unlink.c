/* 
**
** CMSI387: Operating System
** unlink.c
**
** Description: This program implements the 
** "unlink" system call (10) using the syscall function.
**
** Contributions made by Abdul Alzaid, Carlos Agudo, and Jonathan Piatos
**
*/

#include <stdio.h>
#include <sys/file.h>
#include <unistd.h> 
#include <string.h>
#define ERR   (-1)
#define SUCCESS (0)

int main(int argc, char *argv[]){

    int result = syscall(10, argv[1]);

    if (result == 0) {
        //message used simply for testing the syscall
        char *successMessage = "File deleted\n";
        syscall(4, 2, successMessage, strlen(successMessage));
    }
}
