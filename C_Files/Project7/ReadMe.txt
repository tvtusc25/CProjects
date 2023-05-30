CS333 - Project 7 - README
Trey Tuscai
04/28/2022

Directory Layout:
├── ReadMe.txt
├── extension.php
├── my_timing.c
├── my_timing.h
├── task1.swift
├── task1a.c
├── task1b.c
└── task2.swift

0 directories, 8 files

Run and build configuration for C:
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1
Apple clang version 13.0.0 (clang-1300.0.29.30)

Description for each subsection:
Part I:
Memory Management in C

Task A:
The first C programming task included finding the average time per call when allocating a certain amount of memory. I created arrays with 100, 10000, and 1000000 ints to test their malloc time. Each output below was collected from the average of 10 runs. The small allocation (100 ints) was on average the fastest, and the large allocation was the slowest. The larger memory allocation must put more stress on the CPU to cause longer allocation times.  

  Compile:	gcc -o time task1a.c my_timing.c

  Run:		./time 100 (or 10000, 1000000)

  Output (100 ints): 0.001255 seconds

  Output (10000 ints): 0.001291 seconds

  Output (1000000 ints): 0.001325 seconds 


Task B:
The second programming task asked to test if the time of a memory management call will change with the number of allocation and free operations. Similar to the last task, I created arrays with 100, 10000, and 1000000 ints and allocated/deallocated their memory 1000 times. I timed every 100 calls, and the first 100 always took significantly longer. This likely is due to the way I programmed the structure.

  Compile:	gcc -o time2 task1b.c my_timing.c

  Run:		./time2 100 (or 10000, 1000000)

  Output (100 ints): Allocating and freeing memory for any array with 100 ints 1000 times...
		    Time taken from 0 to 100 iterations: 0.001324 seconds
		    Time taken from 100 to 200 iterations: 0.000042 seconds
		    Time taken from 200 to 300 iterations: 0.000048 seconds
		    Time taken from 300 to 400 iterations: 0.000044 seconds
		    Time taken from 400 to 500 iterations: 0.000043 seconds
		    Time taken from 500 to 600 iterations: 0.000043 seconds
		    Time taken from 600 to 700 iterations: 0.000040 seconds
		    Time taken from 700 to 800 iterations: 0.000040 seconds
		    Time taken from 800 to 900 iterations: 0.000042 seconds
		    Time taken from 900 to 1000 iterations: 0.000030 seconds

  Output (10000 ints): Allocating and freeing memory for any array with 10000 ints 1000 times...
		      Time taken from 0 to 100 iterations: 0.001238 seconds
		      Time taken from 100 to 200 iterations: 0.000107 seconds
		      Time taken from 200 to 300 iterations: 0.000151 seconds
		      Time taken from 300 to 400 iterations: 0.000119 seconds
		      Time taken from 400 to 500 iterations: 0.000116 seconds
		      Time taken from 500 to 600 iterations: 0.000120 seconds
		      Time taken from 600 to 700 iterations: 0.000111 seconds
		      Time taken from 700 to 800 iterations: 0.000124 seconds
		      Time taken from 800 to 900 iterations: 0.000117 seconds
		      Time taken from 900 to 1000 iterations: 0.000118 seconds

  Output (1000000 ints): Allocating and freeing memory for any array with 1000000 ints 1000 times...
			Time taken from 0 to 100 iterations: 0.001409 seconds
			Time taken from 100 to 200 iterations: 0.000105 seconds
			Time taken from 200 to 300 iterations: 0.000113 seconds
			Time taken from 300 to 400 iterations: 0.000116 seconds
			Time taken from 400 to 500 iterations: 0.000116 seconds
			Time taken from 500 to 600 iterations: 0.000119 seconds
			Time taken from 600 to 700 iterations: 0.000116 seconds
			Time taken from 700 to 800 iterations: 0.000120 seconds
			Time taken from 800 to 900 iterations: 0.000113 seconds
			Time taken from 900 to 1000 iterations: 0.000121 seconds

Part II:
Swift:
Memory Management in Selected Languages:

Task 1:

The first Swift programming task called for researching memory management algorithms in Swift. All research can be found in wiki. 

  Compile:	swift task1.swift

  Run:		swift task1.swift

  Output:	Output in wiki

Task 2:

The second Swift programming task required undertaking an experiment with automatic memory management and garbage collection. All research can be found in wiki.

  Compile:	swift task2.swift

  Run:		swift task2.swift

  Output:	Output in wiki



Extension:

For my extension, I researched memory management with a second language, PHP. The page and results can be seen on my wiki labeled "Trey Tuscai Project #7 Extension: PHP." It mirrors the Swift layout. For compilation and running, type php filename.php.
