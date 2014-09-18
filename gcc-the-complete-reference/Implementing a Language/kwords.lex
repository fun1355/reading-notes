%%
switch printf("SWITCH ");
case printf("CASE ");
[a-zA-Z][_a-zA-Z0-9]* printf("WORD(%s) ",yytext);
[0-9]+ printf("INTEGER(%s) ",yytext);
\{ printf("LEFTBRACE ");
\} printf("RIGHTBRACE ");
%%