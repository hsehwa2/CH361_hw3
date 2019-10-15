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


// /* parseline - Parse the command line and build the argv array */
// int parseline(char *buf, char **argv){
//     char *delim;        /* Points to first space delimiter */
//     int argc;           /* Number of args */
//     int bg;             /* Background job? */
//     buf[strlen(buf)-1] = ' ';   /* Replace trailing '\n' with space */
//     while (*buf && (*buf == ' ')) /* ignores leading space */
//         buf++;
    
//     /* Build the argv list */
//     argc = 0;
//     while ((delim = strchr(buf,' '))) {
//         argv[argc++] = buf;
//         char end[2] = "\0";
        
//         buf = end+ 1;
//         while (*buf && (*buf == ' ')) /* Ignore spaces */
//             buf++;
//     }

//     argv [argc] = NULL;

//     if (argc == 0) /* Ignore blank line */
//         return 1;
    
//     /* Should the job run in the background? */
//     if ((bg = (*argv[argc-1] == '&')) != 0)
//         argv[--argc] = NULL;
    
//     return bg;
// }

/* eval - Evaluate a command line */
void eval(char *cmdline) {
    
    char *args[MAXARGS];

    

    fgets(cmdline, MAXLINE, stdin);
    cmdline[(strlen(cmdline)-1)] = '\0';
    strtok(cmdline, " ");
    strcpy(*args, cmdline);

    printf("args: %s \n", args[0]);

    if (args[0] == NULL)
        return; /* Ignore empty lines */

    int status;
    pid_t childPid; 
    childPid = fork();

    if (childPid == 0) {
        //printf("child : %s %s", args[0], args);
        execvp(args[0], args);
        printf("error");      
    } else {
        printf("hello \n"); // test to see if it goes into parent
        wait(&status);
    }    
    return;
}






int main(){
    char cmdline[MAXLINE]; /* Command line */
    while (1) {
    /* Read */
        printf("CS 361> ");

        eval(cmdline);
    }
    return 0;
}