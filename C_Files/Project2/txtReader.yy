
%{
//counter variables
//counts vowels, rows, and characters in .txt document
int vowels = 0;
int rows = 1;
int chars = 0;
%}

%%
"a"|"e"|"i"|"o"|"u"     {vowels++; chars++;}
"A"|"E"|"I"|"O"|"U"	{vowels++; chars++;}
\n			rows++;
.			chars++;	 
%%

int main (void)
{
	 //yyin must take correct path to file
	 yyin = fopen("/Users/treytuscai/Desktop/School/CS333/C_Files/Project2/test_files/test.txt", "r");
	 yylex();
	 printf("Vowel Count: %d\n", vowels);
	 printf("Row Count: %d\n", rows);
	 printf("Character Count: %d\n", chars);
	 
}

int yywrap (void)
{
	return 1;
}