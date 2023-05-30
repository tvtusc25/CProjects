//
//  task1b.c
//  
//
//  Created by Trey Tuscai on 4/26/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "my_timing.h"

int main(int argc, char *argv[])
{
    //take array size from command line
    char* a = argv[1];
    int size = atoi(a);
    printf("\nAllocating and freeing memory for any array with %d ints 1000 times...\n", size);
    double time1 = 0;
    double time2 = 0;
    //calculate time and allocate int array
    for(int i = 1; i <= 1000; i++)
    {
        //start original timer at beginnning
        if(i == 1)
        {
            //allocate and free
            time1 = get_time_sec();
            int *arr = malloc(sizeof(int)*size);
            free(arr);
        }
        //every 100 iterations
        else if(i % 100 == 0)
        {
            //allocate and free
            int *arr = malloc(sizeof(int)*size);
            free(arr);
            //print time for every 100 iterations
            time2 = get_time_sec();
            printf("Time taken from %d to %d iterations: ", i-100, i);
            printf("%f seconds\n", time2-time1);
            //reset timer
            time1 = get_time_sec();
        }
        else
        {
            //allocate and free
            int *arr = malloc(sizeof(int)*size);
            free(arr);
        }
    }
    printf("\n");
}

