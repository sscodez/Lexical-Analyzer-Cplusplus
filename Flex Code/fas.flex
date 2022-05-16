%{

    
    #include<stdio.h>
    #include<string.h>

    
    int no_of_tokens = 0;
    int ID = 0 ;
    int KW = 0 ;
    int AO = 0 ;
    int RO = 0 ;
    int SC = 0 ;
    int Sep = 0 ;
    int Del = 0 ;
    int Num=0;

%}

DIGIT [0-9]*
Keywords SSmain|integer|getback|var|floop|wloop|type
%%
{Keywords} {fprintf(yyout,"Keywords:%s\n",yytext);++no_of_tokens;++KW;}
[a-zA-Z_][a-zA-Z0-9_]* {fprintf(yyout,"Identifier:%s\n",yytext);++no_of_tokens;++ID;}
{DIGIT} {fprintf(yyout,"Digit :%s\n",yytext);++no_of_tokens;++Num;}
[+|-|*|/|^]+ {fprintf(yyout,"Arithmetic Operators:%s\n",yytext);++no_of_tokens;++AO;}
[{|}|(|)] {fprintf(yyout,"Separators:%s\n",yytext);++no_of_tokens;++Sep;}
[=|>|<|>=|<=|==]+ {fprintf(yyout,"Relational Operators:%s\n",yytext);++no_of_tokens;++RO;}
; {fprintf(yyout,"SemiColon:%s\n",yytext);++no_of_tokens;++SC;}
"\n" | "\t" | " " {fprintf(yyout,"Delimiters\n",yytext);++no_of_tokens;++Del;}
. {fprintf(yyout,"");}

%%

yywrap() {}

int main() {
    extern FILE *yyin, *yyout;    

    yyin = fopen("a.txt", "r");    

    yyout = fopen("flex-out.fas", "w"); 

    yylex();

    fprintf(yyout,"\n ---------------------------------");
    fprintf(yyout,"\n ---------------------------------");
    fprintf(yyout,"\n No of Tokens #: %d",no_of_tokens);
    fprintf(yyout,"\n ---------------------------------");
    fprintf(yyout,"\n No of Keywords #: %d",KW);
    fprintf(yyout,"\n No of Arithmetic Operators #: %d",AO);
    fprintf(yyout,"\n No of Relational Operators #: %d",RO);
    fprintf(yyout,"\n No of SemiColon #: %d",SC);
    fprintf(yyout,"\n No of Separators #: %d",Sep);
    fprintf(yyout,"\n No of Delimiters #: %d",Del);
    fprintf(yyout,"\n No of ID Numbers #: %d",Num);
    

return 0;
}

 
