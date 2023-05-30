CS333 - Project 1 - README
Trey Tuscai
02/17/2022

Directory Layout:
/Users/treytuscai/Desktop/Project1
├── /Users/treytuscai/Desktop/Project1/task1.c
├── /Users/treytuscai/Desktop/Project1/task2.c
├── /Users/treytuscai/Desktop/Project1/task3.c
├── /Users/treytuscai/Desktop/Project1/task4.c
└── /Users/treytuscai/Desktop/Project1/task5.c

0 directories, 5 files

Run and build configuration for C:
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/Library/Developer/CommandLineTools/SDKs/MacOSX12.1.sdk/usr/include/c++/4.2.1
Apple clang version 12.0.5 (clang-1205.0.22.11)

Description for each subsection:
C:

Task 1:
  
The first C programming task included using an unsigned char to go through each data type and look how the memory is stored. I found that I am using a little-endian machine because the system stores the least significant byte at the smallest memory address and the most significant byte at the largest.

  Compile:	gcc -o task1 task1.c

  Run:		./task1

  Output:	Pointer is 0x7ffee9d20b28 and, it points to a value 103.
		0: 67
		1: 45
		2: 23
		3: 01

Task 2:

The second C programming task involved looping and printing out memory for the first 100ish bytes. At the end of the process, all the bytes currently accessed are displayed in console. It is possible to see the variables defined in you C program as memory. 

  Compile:	gcc -o task2 task2.c

  Run:		./task2

  Output:	0: 20
		1: 5B
		2: 80
		3: E1
		4: FE
		5: 7F
		6: 00
		7: 00
		8: 67
		9: 45
		10: 23
		11: 01
		12: 77
		13: 00
		14: 00
		15: 88
		16: 50
		17: 5B
		18: 80
		19: E1
		20: FE
		21: 7F
		22: 00
		23: 00
		24: 7B
		25: DF
		26: 3F
		27: 0E
		28: 01
		29: 00
		30: 00
		31: 00
		32: 70
		33: 5B
		34: 80
		35: E1
		36: FE
		37: 7F
		38: 00
		39: 00
		40: 01
		41: 00
		42: 00
		43: 00
		44: 00
		45: 00
		46: 00
		47: 00
		48: 60
		49: 5B
		50: 80
		...

Task 3:

The third C programming task had me repeatedly allocate a small amount of memory in a loop for a long time. When not using the free statement, a large amount of memory is required. When using the free statement, memory usage is not a significant problem.

  Compile:	gcc -o task3 task3.c

  Run:		./task3

  Output:	No output

Task 4:

The fourth C programming task was setting up a struct and allocating memory for it. The sizeof result did not match my expectation because padding is involved and takes up more bytes than just the variables. There are gaps in the way the field of the structure are laid out due to padding.

  Compile:	gcc -o task4 task4.c

  Run:		./task4

  Output:	Size of struct: 12

Task 5:

The fifth C programming task called for use of the strcpy function to see whether it is robust in my C compiler or not. My compiler crashed when I attempted to use a too-long string into the char array. 

  Compile:	gcc -o task5 task5.c

  Run:		./task5

  Output:	Compiler crashes

Extension:

In my extension, I found the floating point number in C to which you can add one and get back the same number. It is 4294967296 or 2^32 because that is the maximum value that can be encoded.


