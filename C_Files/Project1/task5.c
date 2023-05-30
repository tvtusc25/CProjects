/*
 * task5.c
 *
 *  Created on: Feb 16, 2022
 *      Author: treytuscai
 */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>


	//main method
	int main (int arg, char *argv[])
	{
		char str2[3];
		int test = 0;
		strcpy(str2, "hello");
		if (test==0)
			printf("safe");
		if (test!=0)
			printf("hacked");
		//compiler crashed
        return 0;
    }



