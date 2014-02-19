#include <stdio.h>
#include <sys/file.h>

#define ERR   (-1)
#define SUCCESS (0)

     int main();

     int main(argc, argv)
     int argc;
     char *argv[];

     {

        if (argc != 2){
           printf("Usage:  %s filename\n", argv[0]);
        } if (access (argv[1], F_OK) == ERR){
           perror(argv[1]);
        } if (access (argv[1], W_OK) == ERR) {
           fprintf(stderr,"File:  %s  is write protected!\n", argv[1]);
        } if (unlink (argv[1]) == ERR) {
           perror(argv[1]);
        }
    }
