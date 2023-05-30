/*
 * task2.c
 *
 *  Created on: Feb 16, 2022
 *      Author: treytuscai
 */

	#include <stdio.h>
	#include <stdlib.h>

	//accesses and prints the first 100 bytes of memory
	void MemoryAmount()
	{
		//basic variables
		char a = 0x088;
		short b = 0x077;
		int c = 0x01234567;
		unsigned char *ptr;
		ptr = (unsigned char *)&(ptr);

		//prints first 100 bytes
		//variable values CAN be seen in memory
		for(int i=0; i<100; i++)
		{
			printf("%d: %02X\n", i, ptr[i]);
		}
	}

	int main (int arg, char *argv[])
	{
		MemoryAmount();
		return 0;
	}



