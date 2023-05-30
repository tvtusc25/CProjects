letterFront    [A-Ma-m]
letterBack     [N-Zn-z]
%{
    int count;
%}
%%

{letterFront}    { printf("%c", yytext[count]+13); }
{letterBack}    { printf("%c", yytext[count]-13); }
	 
%%

int main ( int argc, char *argv[] )
{	 
	 yylex(); 
	 return 0;
	 
}

int yywrap (void)
{
	return 1;
}