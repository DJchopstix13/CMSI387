/* Jonathan Piatos
** CMSI387: Operating Systems
** fork-exec.c
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TKN 10
#define CMD_LENGTH 256
#define DIR_SIZE 1024

/*
 * Tokenizes user input.  This method will 
 * store string into an array
 *
 */
int tokening_input (char *command, char *arg[]) {
    
    //initialize index and delimeter
    int i = 0;
    char *delimeter = " \n";

    //handles strtok parsing
    char *arguments = strtok(command, delimeter);

    while (arguments != NULL) {
        arg[i] = arguments;
        arguments = strtok(NULL, delimeter);
        i++;
    }

    arg[i] = NULL;
    return 0;
}

/*
 * Demonstrates the use of the fork() and exec()
 * functions.
 *
 */
int main() {

    //strings to hold commands
    char command[CMD_LENGTH];
    char *arg[MAX_TKN];
    
    do {
        
        //Displays current directory
        char directory[DIR_SIZE];
        getcwd(directory, sizeof(directory));
        printf("Enter your command: ", directory);        

        fgets(command, sizeof(command), stdin);

         // Stops everything if the only character is a newline 
         if (strlen(command) > 1) {
            
            //check "&" command
            int willWait = 1;
            if (command[strlen(command) - 2] == '&') {
                command[strlen(command) - 2] = '\0';
                willWait = 0;
            }
        
            //Parses input
            tokening_input(command, arg);
        
            //Checks "cd" command
            if (strcmp("cd", arg[0]) == 0) {
                
                chdir(arg[1]);

            } 

            //Checks for secret-system-call
            else if (strcmp("secret-system-call", arg[0]) == 0) { 
                
                long int call = syscall(351);
                printf("Syscall 351 invoked.\n\n");
            
            } else {
                //based off of Bazaar's original fork-exec.c file
                
                /* Variable that will store the fork result */
                pid_t pid;

                /* Perform the actual fork */
                pid = fork();
                if (pid  < 0) {
                    /* Error condition */
                    fprintf(stderr, "Fork failed\n");
                    return -1;
                } else if (pid == 0) {
                    /* Child process */
                    printf("\n");
                    execvp(arg[0], arg);
                } else {
                    /* Parent Process */
                    int result;
                    if (willWait == 1) {
                        wait(&result);
                    }
                    printf("\nAll done; result = %d\n\n", result);
                }
            }
        }
    } while (!feof(stdin));

    return 0;
} 