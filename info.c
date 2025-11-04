/*
* Name: Ashwin Senthil
* Date: 11/3/2025
* Assignment: lab 9
*
* info.c
*
* compile instructions - makefile
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h> //POSIX header
#include <time.h>


int main(){

    //struct to hold time
    struct timespec ts;

    //get time in nanoseconds from sys clock
    clock_gettime(CLOCK_REALTIME, &ts);
    printf("the current time is (in nanoseconds): %lf\n", ts.tv_nsec + (ts.tv_sec * 1E9)); //display time


    //new struct to hold system info -- os and version
    struct utsname sysinfo;

    //fill struct with data 
    uname(&sysinfo); //using uname fill the address with the info needed

    //print system network if its not empty
    if(strlen(sysinfo.nodename)){ //.nodename gets the name of network
        printf("System network name: %s\n", sysinfo.nodename); 
    }

    //print OS name if its not empty
    if(strlen(sysinfo.sysname)){ //.sysname gets the name of system
        printf("OS name is: %s\n", sysinfo.sysname);
    }

    //get release if not empty
    if(strlen(sysinfo.release)){ //.release -> gets release
        printf("Release is: %s\n", sysinfo.release);
    }

    //print OS version string if not empty
    if(strlen(sysinfo.version)){ //gets version string 
        printf("OS version is %s\n", sysinfo.version);
    }

    //finally hardware type if not empty
    if(strlen(sysinfo.machine)){
        printf("hardware type is %s\n", sysinfo.machine);
    }

    
    //buffer for host name
    char hostname[26];

    //get hostname and store in buffer
    gethostname(hostname, sizeof(hostname));

    //printf if not empty
    if(strlen(hostname)){
        printf("hostname is %s", hostname);
    }

    //cpu time
    long cpus = sysconf(_SC_NPROCESSORS_ONLN); //check how many usable processors they are in sys and store in cpus var

    //print cpus
    printf("number of usable cpus: %ld\n", cpus);


    //physical memory time
    long pages = sysconf(_SC_PHYS_PAGES); //get total number of pages in sysconf and store in pages variable

    //get free pages
    long free_page = sysconf(_SC_AVPHYS_PAGES); //get number of free page and store in variable

    //get size of page in memory in bytes
    long page_size = sysconf(_SC_PAGESIZE); //gets pagesize of sysconf of each mem page and store in page size

    //calculate and print
    printf("TOTAL PHYSICAL MEMORY in bytes: %ld\n", pages * page_size);
    printf("FREE PHYSICAL MEMORY in bytes: %ld\n", free_page * page_size);

    return 0; //end



}

