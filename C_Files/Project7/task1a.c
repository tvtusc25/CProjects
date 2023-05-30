//
//  task1a.c
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
    printf("Allocating memory for %d ints in array...\n", size);
    //calculate time and malloc int array
    double time1 = get_time_sec();
    int *arr = malloc(sizeof(int)*size);
    double time2 = get_time_sec();
    printf("Time taken: %f seconds\n", time2-time1);
}
