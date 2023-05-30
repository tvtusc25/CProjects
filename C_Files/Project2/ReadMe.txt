CS333 - Project 2 - README
Trey Tuscai
02/24/2022

Directory Layout:
Project2
├── encode.yy
├── encode.yy.c
├── htmlReader.yy
├── htmlReader.yy.c
├── parser.yy
├── parser.yy.c
├── test_files
│   ├── htmltest.txt
│   ├── math.txt
│   ├── p2.txt
│   └── test.txt
├── txtReader.yy
└── txtReader.yy.c

1 directory, 12 files


Run and build configuration for C:
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/Library/Developer/CommandLineTools/SDKs/MacOSX12.1.sdk/usr/include/c++/4.2.1
Apple clang version 12.0.5 (clang-1205.0.22.11)

Description for each subsection:
C:

Encode:
  
The first C programming task included using flex to flip any character (a-z or A-Z) 13 spaces forward in the alphabet.

  Compile:	gcc -o encode encode.yy.c -ll

  Run:		echo "blah and another blah" | ./encode

  Output:	oynu naq nabgure oynu

Text Reader:

The second C programming task involved making a program read in a text file and print the number of rows characters, and vowels. Test file is included within folder. However, you must change code to point to a text file of choice. 

  Compile:	gcc -o txtReader txtReader.yy.c -ll

  Run:		./txtReader

  Output:	Vowel Count: 15
		Row Count: 4
		Character Count: 24

HTML Reader:

The third C programming task had strip the html file of all tags, comments, and white space except for a blank line where "<p>" is. Test html file is included within folder. However, you must change code to point to a text file of choice. 

  Compile:	gcc -o htmlReader htmlReader.yy.c

  Run:		./htmlReader

  Output:	ThisisapagetitleHereisaheader
		Hereissomebodytextinaparagraph
		Hereisalinktocs.colby.eduinsideaparagraph.

Task 4:

The fourth C programming task called for implementation of a parser for Clite. Test math file is included within folder. However, you must change code to point to a text file of choice. 


  Compile:	gcc -o parser parser.yy.c

  Run:		./parser

  Output:	Keyword-int
		Identifier-main
		Open-paren
		Close-paren
		Open-bracket
		Keyword-int
		Identifier-a
		Assignment
		Integer-6
		Keyword-int
		Identifier-b
		Assignment
		Float-5.0
		Keyword-if
		Open-paren
		Identifier-a
		Comparison-<
		Identifier-b
		Close-paren
		Open-bracket
		Identifier-a
		Assignment
		Identifier-a
		Operator-+
		Identifier-b
		Close-bracket
		Close-bracket



Extension:

For my extensions, I got comments to work properly for Clite and did a second language. Both single and multi-line comments are ignored, and the second language is up on the wiki.

