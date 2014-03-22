/* 
**
** CMSI387: Operating System
** sysinfo.c
**
** Description: This program demonstrates invocation of the sysinfo
** system call (116) using the syscall function. 
**
** Contributions made by Abdul Alzaid, Carlos Agudo, and Jonathan Piatos
** 
*/

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {


    struct sysinfo result;
    syscall(116, &result);
    
    // Display some of the returned RAM information.
    printf("Total RAM: %ld, free RAM: %ld, shared Ram %ld, buffer Ram %ld\n, total swap %ld, total processes %d, Total high memory size %ld\n", result.totalram, result.freeram, result.sharedram, result.bufferram, result.totalswap, result.procs, result.totalhigh);
}
