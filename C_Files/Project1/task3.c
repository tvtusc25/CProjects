/*
 * task3.c
 *
 *  Created on: Feb 16, 2022
 *      Author: treytuscai
 */

	#include <stdio.h>
	#include <stdlib.h>

	//repeatedly allocates a small amount of memory in a loop
	//memory requirements explode if not freed
	void MemoryAllocation()
	{
		//allocates memory 100000 times
		for (int i = 0; i < 100000; i++)
		{
			int *ptr = (int *)malloc(sizeof(int));
			//frees pointer to free memory pressure
			free(ptr);
		}
	}

	int main (int arg, char *argv[])
	{
		MemoryAllocation();
		return 0;
	}



