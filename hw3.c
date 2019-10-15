#define MAXARGS 128
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MAXLINE 100


/* eval - Evaluate a command line */
void eval(char *cmdline) {
    
    char *args[MAXARGS];

    fgets(cmdline, MAXLINE, stdin);
    cmdline[(strlen(cmdline)-1)] = '\0';
    strtok(cmdline, " ");
    strcpy(*args, cmdline);
    args[(strlen(*args)-1)] = '\0';

   

    if (args[0] == NULL)
        return; /* Ignore empty lines */

    int status;
    pid_t childPid; 
    childPid = fork();

    if (childPid == 0) {
        execvp(args[0], args);    
    } else {
        wait(&status);
    }    
    return;
}






int main(){
    char cmdline[MAXLINE]; /* Command line */
    while (1) {
    /* Read */
        printf("CS361 >");

        eval(cmdline);
    }
    return 0;
}