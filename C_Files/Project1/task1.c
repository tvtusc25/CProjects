/*
 * task1.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Trey Tuscai
 */

	#include <stdio.h>
	#include <stdlib.h>

	//prints the pointer and its value
	//prints the byte order
	void MemoryAccess()
	{
		//basic variables
		char a = 'a';
		short b = 1;
		int c = 0x01234567;
		long d = 3;
		float e = 4.0;
		double f = 5.0;

		//unsigned char pointer
		unsigned char *ptr = (unsigned char *)&(c);

		//prints pointer value and integer value
		printf("Pointer is %p and, it points to a value %i.\n", ptr, *ptr);

		//prints the bytes in order of our int
		for(int i=0; i<sizeof(int); i++)
		{
			//Little-endian machine
			printf("%d: %02X\n", i, ptr[i]);
		}
	}

	int main (int arg, char *argv[])
	{
		MemoryAccess();
		return 0;
	}



