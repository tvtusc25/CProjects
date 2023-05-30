//
//  sigfpe.c
//  
//
//  Created by Trey Tuscai on 4/13/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signo)
{
    //signal handler
    printf("Floating Point Exception!");
    //exit or program will run forever
    exit(0);
}

int main(void)
{
    //signal call
    signal(SIGFPE, handler);

    //divide by zero to cause SIGFPE
    int j = 1;
    j = j / 0;

    //never printed
    printf("After divide by zero");
    return(0);
}
