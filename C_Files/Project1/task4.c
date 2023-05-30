/*
 * task4.c
 *
 *  Created on: Feb 16, 2022
 *      Author: treytuscai
 */

	#include <stdio.h>
	#include <stdlib.h>

	//struct with basic variables
	typedef struct A
	{
		int a;        //Offset: 0, size: 4 bytes
		short b;      //Offset: 4, size: 2 bytes
		char c;		  //Offset: 6, size: 1 bytes
		short d;      //Offset: 7, size: 2 bytes
					  //Should be 9 bytes
	} Container;

	// allocates memory for the struct
	void MemoryLayout()
	{
		Container *cp= (Container *)malloc(sizeof(Container));
		cp->a = 1;
		cp->b = 2;
		cp->c = 'c';
		cp->d = 4;

		//sizeof is not what is expected due to padding
		printf("Size of struct: %ld\n", sizeof(struct A));

		unsigned char *ptr = (unsigned char *)&(ptr);

		//shows memory layout
		//there are gaps in the layout due to padding
		/*for(int i=0; i<sizeof(struct A); i++)
		{
			printf("%02X", ptr[i]);
		}*/
		free(cp);
	}

	int main (int arg, char *argv[])
	{
		MemoryLayout();
		return 0;
	}



