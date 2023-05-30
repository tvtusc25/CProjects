//
//  factorial.c
//  
//
//  Created by Trey Tuscai on 3/10/22.
//

#include <stdio.h>
#include <stdlib.h>

//basic recursive factorial function
int factorial (int num)
{
    //if 0 return 1
    if(num == 0)
        return 1;
    //else recursively multiply
    else
        return (num*factorial(num-1));
}

int main (int argc, char *argv[])
{
    //declaring pointer
    int (*calc)(const int);
    
    //calc is the pointer to factorial
    calc = &factorial;
    
    //access command line argument 1 and convert to int
    //then use calc pointer to call factorial w/ arg 1
    printf("%i",(*calc)(atoi(argv[1])));
    
    return 0;
}
