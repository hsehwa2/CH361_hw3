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
    char *arg;
    int count = 0;

    fgets(cmdline, MAXLINE, stdin);
    cmdline[(strlen(cmdline)-1)] = '\0';
    arg = strtok(cmdline, " ");
    args[count] = arg;
    count++;
    while(arg != NULL){
        arg = strtok(NULL, " ");
        args[count] = arg;
        count++;
    }

    
    /*
    strcpy(*args, cmdline);
    args[(strlen(*args)-1)] = '\0';
    */
   

    if (args[0] == NULL)
        return; /* Ignore empty lines */

    int status;
    int childPid; 
    childPid = fork();

    if (childPid < 0){
        printf("ERROR");
        return;
    }
    if (childPid == 0) {
        execvp(args[0], args);    
    } else {
        wait(&status);
        printf("pid: %d status: %d\n", childPid, WEXITSTATUS(status));
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