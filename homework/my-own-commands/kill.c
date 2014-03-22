/*
** 
** CMSI387: Operating System
** kill.c 
**
** This program demonstrates invocation of the kill system call
** (37) using the syscall function.  Some of its output is then displayed.
**
** Contributions made by Abdul Alzaid, Carlos Agudo, and Jonathan Piatos
**
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>  

int main(int argc, char *argv[]) {

    int result = syscall(37, atoi(argv[1]), atoi(argv[2]));

    if (result == -1) {
        printf("kill: `%s`: %s\n", argv[1], strerror(errno));
    }
}