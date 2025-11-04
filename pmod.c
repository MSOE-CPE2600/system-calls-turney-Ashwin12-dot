/*
* Name: Ashwin Senthil
* Date: 11/3/2025
* Assignment: lab 9
*
* mod.c
*
* compile instructions - makefile
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]){

    nice(10); //lower priority

    struct timespec asked = {1, 83727638};
    struct timespec remaining;
    nanosleep(&asked, &remaining);
    printf("goodbye\n");
    return 0; 

}