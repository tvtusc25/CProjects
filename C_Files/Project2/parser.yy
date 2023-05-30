
KEYWORD "if"|"else"|"while"|"for"|"int"|"float"
ID [a-z][a-z0-9]*
COMPARISON "=="|"<"|">"|"<="|">="
ASSIGNMENT "="
OPERATOR "+"|"-"|"*"|"/"
OPEN_BRACKET "{"
OPEN_PAREN "("
CLOSE_BRACKET "}"
CLOSE_PAREN ")"
DIGIT [0-9]
SEMI_COLON ";"
SINGLE_LINE \/\/(.*)
MULTI_LINE "/*"([^*]|(\*+[^*/]))*\*+\/

%{
%}

%%
{KEYWORD}		 {printf("Keyword-%s\n",yytext);}
{ID}			 {printf("Identifier-%s\n",yytext);}
{COMPARISON}		 {printf("Comparison-%s\n",yytext);}
{ASSIGNMENT}		 {printf("Assignment\n");}
{OPERATOR}		 {printf("Operator-%s\n",yytext);}
{OPEN_PAREN}		 {printf("Open-paren\n");}
{OPEN_BRACKET}		 {printf("Open-bracket\n");}
{CLOSE_PAREN}		 {printf("Close-paren\n");}
{CLOSE_BRACKET}		 {printf("Close-bracket\n");}
{DIGIT}+		 {printf("Integer-%s\n",yytext);}
{DIGIT}+"."{DIGIT}*	 {printf("Float-%s\n",yytext);}
{SEMI_COLON}
{SINGLE_LINE}
{MULTI_LINE}
[" "\t\n]+

%%

int main (void)
{
	 //yyin must take correct path to file
	 yyin = fopen("/Users/treytuscai/Desktop/School/CS333/C_Files/Project2/test_files/math.txt", "r");
	 yylex();
	 
}

int yywrap (void)
{
	return 1;
}