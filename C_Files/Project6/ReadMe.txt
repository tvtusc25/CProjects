CS333 - Project % - README
Trey Tuscai
03/31/2022

Directory Layout:
/Users/treytuscai/Desktop/Project6
├── ReadMe.txt
├── errorhandling.swift
├── sigfpe.c
├── sigint.c
├── sigsegv.c
├── wctest.txt
├── wordcounter.c
├── wordcounter.h
├── wordcounter.php
└── wordcounter.swift

0 directories, 10 files

Run and build configuration for C:
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1
Apple clang version 13.0.0 (clang-1300.0.29.30)

Description for each subsection:
Part I:
File I/O and String in C:

Task 1:
  
The first C programming task included implementing a word counter in C.

  Compile:	gcc -o wc wordcounter.c

  Run:		./wc filename.txt

  Output:	the: 17
		of: 7
		and: 6
		was: 5
		with: 4
		in: 4
		windows: 3
		a: 3
		up: 2
		were: 2
		but: 2
		broken: 2
		been: 2
		had: 2
		portion: 2
		central: 2
		wings: 2
		outsides: 1
		attention: 1
		deep: 1
		examined: 1
		lawn: 1
		illtrimmed: 1
		down: 1
		slowly: 1
		walked: 1
		holmes: 1
		visit: 1
		our: 1
		moment: 1
		at: 1
		workmen: 1
		any: 1
		signs: 1
		no: 1
		there: 1
		into: 1
		stonework: 1
		wall: 1
		end: 1
		against: 1
		erected: 1
		scaffolding: 1
		some: 1
		resided: 1
		family: 1
		where: 1
		this: 1
		that: 1
		showed: 1
		chimneys: 1
		from: 1
		curling: 1
		smoke: 1
		blue: 1
		blinds: 1
		modern: 1
		comparatively: 1
		block: 1
		righthand: 1
		repair: 1
		better: 1
		little: 1
		ruin: 1
		picture: 1
		caved: 1
		partly: 1
		roof: 1
		while: 1
		boards: 1
		wooden: 1
		blocked: 1
		these: 1
		one: 1
		side: 1
		each: 1
		on: 1
		out: 1
		thrown: 1
		crab: 1
		claws: 1
		like: 1
		curving: 1
		two: 1
		high: 1
		stone: 1
		lichenblotched: 1
		grey: 1
		building: 1

Task 2:

The second programming task called for signal handling in C.

a.) Write a program that response to SIGINT
  Compile:	gcc -o int sigint.c

  Run:		./int

  Output:        Interrupted! (When cntl-C is pressed)

b.)Write a program that response to SIGFPE
  Compile:	gcc -o fpe sigfpe.c

  Run:		./fpe

  Output:        Floating Point Exception!


c.)Write a program that response to SIGSEGV
  Compile:	gcc -o segv sigsegv.c

  Run:		./segv

  Output:        Segmentation Fault!

Part II:
Swift:
Functions and File I/O in Selected Languages:

Task 1:

The first Swift programming task called for creating a word counter (same as Part 1).
  Compile:	swift wordcounter.swift

  Run:		swift wordcounter.swift

  Output:	Output in wiki

Task 2:

The second Swift programming task required answering questions regarding File I/O. (In wiki)

Task 3:

The third Swift programming task addressed error handling.

  Compile:	swift errorhandling.swift

  Run:		swift errorhandling.swift

  Output:	Output in wiki



Extension:

For my extension, I created a word counter over again with a second language, PHP. The page and results can be seen on my wiki labeled "Trey Tuscai Project #6 Extension: PHP." It mirrors the Swift layout. For compilation and running, type php filename.php.

