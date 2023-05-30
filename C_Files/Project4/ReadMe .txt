CS333 - Project 4 - README
Trey Tuscai
03/10/2022

Directory Layout:
/Users/treytuscai/Desktop/Project4
├── factorial.c
├── quicksort.c
├── task1.php
├── task1.swift
├── task2.php
├── task2.swift
├── task3.php
└── task3.swift

0 directories, 8 files

Run and build configuration for C:
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1
Apple clang version 13.0.0 (clang-1300.0.29.30)

Description for each subsection:
Part I:
C Semantics:

Task 1:
  
The first C programming task included implementing a quick sort method. The Rules: Given an array of random integers, sort the array in a way that the even numbers appear first and the odd numbers appear later. The even numbers should be sorted in descending order and the odd numbers should be sorted in ascending order.

  Compile:	gcc -o qsort quicksort.c

  Run:		./qsort

  Output:	The sorted array is: 12 10 8 6 4 2 0 1 3 5 7 9 11 13 

Task 2:

The second C programming task involved writing a function that takes in an integer argument and returns its factorial value as an integer. 

  Compile:	gcc -o fact factorial.c

  Run:		./fact

  Output:	Factorial of input number


Part II:
Swift:
All requirements are in wiki

Task 1:

The first Swift programming task called for creating a program to show the the provided control flow statements.


  Compile:	swift task1.swift

  Run:		swift task1.swift

  Output:	Purely for example. No useful output 

Task 2:

The second Swift programming task called for writing a program to show how functions are treated.


  Compile:	swift task2.swift

  Run:		swift task2.swift

  Output:	Purely for example. No useful output 

Task 3:

The third Swift programming task called for implementing a generic insertion sort algorithm. 


  Compile:	swift task3.swift

  Run:		swift task3.swift

  Output:	On wiki page

Extension:

For my extension, I did part II over again with a second language, PHP. The page and results can be seen on my wiki labeled "Trey Tuscai Project #4 Extension: PHP." It mirrors the Swift layout. For compilation and running, type php filename.php.

