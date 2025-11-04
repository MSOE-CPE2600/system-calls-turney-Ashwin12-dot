/*
* Name: Ashwin Senthil
* Date: 11/3/2025
* Assignment: lab 9
*
* pinfo.c
*
* compile instructions - makefile
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    pid_t pid; //hold process ID
    int policy; //hold policy
    int priority; //hold process priority

    //determine which pid to use

    if(argc == 2){
        pid = atoi(argv[1]); //convert to int
    } else {
        pid = getpid(); //no argument means give current pid. man page
    }


    //retrieve scheduling policy for the process
    policy = sched_getscheduler(pid); //this is really important for step 4

    //if -1, give error
    if(policy == -1){
        perror("sched_getscheduler"); //std error msg
        return 1; //exit prog
    }

    //retrieve process priority 
    // use get priority -> returns value -20 (highest) to 19 (lowest)
    errno = 0;  //reset errno
    priority = getpriority(PRIO_PROCESS, pid); //this is the getpriority one im talking about 
    //-20 runs more and is "less nice" 19 runs less and is "nice"

    //if ernno isn't being changed -> somethings wrong!
    if(errno != 0){
        perror("getpriority"); //error msg
        return 1; //exit prog
    }


    //display info -- last step

    printf("Process ID: %d\n", pid);
    printf("Process priority: %d\n", priority);


    //convert scheduling policy into a readable string

    switch(policy){

        //the cases we get actually convert from kernal values we got earlier in coding
        //reference get priority -> it then converts by sched_getscheduler, generating our cases
        //so we can use a simple switch case like i do here
        case SCHED_OTHER:
        printf("scheduling method is SCHED_OTHER\n");
        break;
        
        case SCHED_FIFO: 
        printf("scheduling method is SCHED_FIFO\n");
        break;

        case SCHED_RR:
        printf("Scheduling method is SCHED_RR\n");
        break;

        case SCHED_BATCH:
        printf("scheduling method is sched_batch\n");
        break;

        case SCHED_IDLE:
        printf("scheduling method is idle\n");
        break;

        default:
        printf("unknown method\n");
        break;
    }
    return 0; //exit program
}