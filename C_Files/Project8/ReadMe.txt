CS333 - Project 8 - README
Trey Tuscai
05/05/2022

Directory Layout:
├── PartI
│   ├── task1
│   │   ├── benford_para.c
│   │   ├── benford_parb.c
│   │   ├── benford_parc.c
│   │   ├── benford_pard.c
│   │   ├── benford_pare.c
│   │   ├── benford_parf.c
│   │   ├── benford_sequential.c
│   │   ├── longer.bin
│   │   ├── longer_nonBenford.bin
│   │   ├── medium.bin
│   │   ├── my_timing.c
│   │   ├── my_timing.h
│   │   └── super_short.bin
│   └── task2
│       ├── IMG_4203.ppm
│       ├── colorize.c
│       ├── my_timing.c
│       ├── my_timing.h
│       ├── ppmIO.c
│       └── ppmIO.h
├── PartII
│   └── task2
│       ├── IMG_4203.ppm
│       ├── imageman.py
│       └── imageman_sequential.py
└── ReadMe.txt

5 directories, 23 files

Run and build configuration for C:
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1
Apple clang version 13.0.0 (clang-1300.0.29.30)

Description for each subsection:
Part I:
Parallel Programming in C

Task 1:
The first C programming task included implementing several parallel versions of Benford's Law. I used 8 threads and the medium sized bin. Multiple threads compute much faster than sequential. The fastest on average run time was the local counter array, with final update protected by array of mutexes. Mutex locks ensure concurrent threads do not simultaneously execute the same program segment, but also slow them down. In this case, mutex locks prevent the global counters from encountering a race condition with the 8 threads. You should use mutexes when modifying global variables.

All Outputs: There are 3217 1's
             There are 1779 2's
             There are 1121 3's
             There are 907 4's
             There are 745 5's
             There are 668 6's
             There are 591 7's
             There are 901 8's
             There are 893 9's

Note: The filenames change by the end letter.
A.)Global Counter Array Protected by Single Mutex
   Compile:	gcc -o benford_par my_timing.c benford_para.c -lm -lpthread
   Run:		./benfordpar
   5 Runtimes:   0.002703 sec, 0.003915 sec, 0.004777 sec, 0.004212 sec, 0.005701 sec
   Runtime Min:  0.002703 sec
   Runtime Max:  0.005701 sec
   Runtime Mean: 0.004262 sec
   	
B.)Global Counter Array Protected by Array of Mutexes
   Compile:	gcc -o benford_par my_timing.c benford_parb.c -lm -lpthread
   Run:		./benfordpar
   5 Runtimes:   0.001330 sec, 0.002231 sec, 0.002131 sec, 0.002193 sec, 0.002325 sec
   Runtime Min:  0.001330 sec
   Runtime Max:  0.002325 sec
   Runtime Mean: 0.002042 sec

C.)Local Counter Array, with Final Update Protected by Single Mutex
   Compile:	gcc -o benford_par my_timing.c benford_parc.c -lm -lpthread
   Run:		./benfordpar
   5 Runtimes:   0.001499 sec, 0.001617 sec, 0.002388 sec, 0.001678 sec, 0.001839 sec
   Runtime Min:  0.001499 sec
   Runtime Max:  0.002388 sec
   Runtime Mean: 0.001804 sec

D.)Local Counter Array, with Final Update Protected by Array of Mutexes
   Compile:	gcc -o benford_par my_timing.c benford_pard.c -lm -lpthread
   Run:		./benfordpar
   5 Runtimes:   0.001938 sec, 0.000966 sec, 0.001018 sec, 0.001683 sec, 0.001712 sec
   Runtime Min:  0.000966 sec
   Runtime Max:  0.001938 sec
   Runtime Mean: 0.001463 sec

E.)Global Counter Array of Arrays, Grouped by Thread, no Mutex
   Compile:	gcc -o benford_par my_timing.c benford_pare.c -lm -lpthread
   Run:		./benfordpar
   5 Runtimes:   0.001811 sec, 0.001556 sec, 0.001855 sec, 0.001918 sec, 0.001951 sec
   Runtime Min:  0.001556 sec
   Runtime Max:  0.001951 sec
   Runtime Mean: 0.001818 sec

F.)Global Counter Array of Arrays, Grouped by Digit, no Mutex
   Compile:	gcc -o benford_par my_timing.c benford_parf.c -lm -lpthread
   Run:		./benfordpar
   5 Runtimes:   0.001984 sec, 0.001731 sec, 0.001761 sec, 0.001593 sec, 0.001024 sec
   Runtime Min:  0.001024 sec
   Runtime Max:  0.001984 sec
   Runtime Mean: 0.001618 sec


Task 2:
The second programming task asked us to manipulate a .ppm image with a pixel-wise operator and parallelism. The compile times shorten the more threads that are used.

1 Thread:
  Compile:	gcc -o colorize -I. my_timing.c colorize_sequential.c ppmIO.c -lm
  Run:		./colorize IMG_4203.ppm
  5 Runtimes:    0.030190 sec, 0.022102 sec, 0.018304 sec, 0.030460 sec, 0.023024 sec
  Runtime Min:   0.018304 sec
  Runtime Max:   0.030460 sec
  Runtime Mean:  0.024819 sec

2 Threads:
  Compile:	gcc -o colorize -I. my_timing.c colorize.c ppmIO.c -lm
  Run:		./colorize IMG_4203.ppm
  5 Runtimes:    0.023843 sec, 0.016284 sec, 0.029273 sec, 0.021179 sec, 0.021134 sec
  Runtime Min:   0.016284 sec
  Runtime Max:   0.029273 sec
  Runtime Mean:  0.022342 sec

4 Threads: 	
   Compile:      gcc -o colorize -I. my_timing.c colorize.c ppmIO.c -lm
   Run:		./colorize IMG_4203.ppm
   5 Runtimes:   0.020805 sec, 0.023997 sec, 0.021722 sec, 0.020041 sec, 0.019474 sec
   Runtime Min:  0.019474 sec
   Runtime Max:  0.023997 sec
   Runtime Mean: 0.021207 sec

  

Part II:
Swift:
Parallel Programming in Selected Languages:

Task 1:

The first Swift programming task called for researching parallelism in Swift. All research can be found in wiki. 

  Compile:	No file

  Run:		No file

  Output:	No file

Task 2:

The second Swift programming task required implement task 2 from part I. I compared 1, 2, and 4 threads. All research can be found in wiki.

  Compile:	python3 image_man.py

  Run:		python3 image_man.py

  Output:	Output in wiki



Extension:

For my extension, I researched parallelism with a second language, PHP. The page and results can be seen on my wiki labeled "Trey Tuscai Project #8 Extension: PHP." It mirrors the Swift layout. For compilation and running, type php filename.php.
