//
//  interrupt.c
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
    printf("Interrupted!\n");
    exit(0);
}
  
int main(void)
{
    //signal call
    signal(SIGINT, handler);
    while (1)
        sleep(1);
    return(0);
}
