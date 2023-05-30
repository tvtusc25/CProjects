//
//  sigsegv.c
//  
//
//  Created by Trey Tuscai on 4/13/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signo)
{
    //signal handler
    printf("Segmentation Fault!\n");
    //exit or program will run forever
    exit(0);
}


int main(void)
{
    //segfault
    char* ptr = 0;
    //signal call
    signal(SIGSEGV, handler);
    *ptr = 0;
    return(0);
}
