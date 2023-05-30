/**
 * Given an array of random integers, sort it in such a way that the even
 * numbers appear first and the odd numbers appear later. The even numbers
 * should be sorted in descending order and the odd numbers should be sorted
 * in ascending order.
 *
 * Ying Li
 * 08/02/2016
 */

#include <stdio.h>
#include <stdlib.h>

/* the comparator function used in qsort */
int comparator (const void *p, const void *q) {
    // Your code here
    //two int variables that reference and deref p or q
    int num1 = *(int*)p;
    int num2 = *(int*)q;
    
    //tests if both numbers are odd
    if((num1 % 2) == (num2 % 2) && (num1 % 2) == 1)
    {
        //returns the smaller number first
        return num1 - num2;
    }
    //test if both numbers are even
    else if((num1 % 2) == (num2 % 2) && (num1 % 2) == 0)
    {
        //returns the larger number first
        return num2 - num1;
    }
    //returns the even values first then odd
    return (num1 % 2) - (num2 % 2);
}

int main (int argc, char **argv) {
    //array
    int ary[] = {10, 11, 1, 8, 9, 0, 13, 4, 2, 7, 6, 3, 5, 12};
    
    //array size
    int size = sizeof(ary) / sizeof(int);
    
    //qsort call
    qsort((void *) ary, size, sizeof(int), comparator);
    
    //prints sorted array
    printf("The sorted array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", ary[i]);
    }
    printf("\n");
    
    return 0;
}
