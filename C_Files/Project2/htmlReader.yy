
return "<p>"
comment <!--([^-]|-[^-]|--+[^->])*--+>
tag <[^>]*>

%{
%}

%%
{return}	{printf("\n");}
[" "\t\n]+
{comment}
{tag}

%%

int main (void)
{
	 //yyin must take correct path to file
	 yyin = fopen("/Users/treytuscai/Desktop/School/CS333/C_Files/Project2/test_files/htmltest.txt", "r");
	 yylex();
	 
}

int yywrap (void)
{
	return 1;
}