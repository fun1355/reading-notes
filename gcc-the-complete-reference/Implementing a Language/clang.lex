/* clang.lex */
%{
#include "clang.tab.h"
extern int yylval;
extern char *yytext;
%}

%%
set { return(SETTOKEN); }
color { return(COLORTOKEN); }
location { return(LOCATIONTOKEN); }
draw { return(DRAWTOKEN); }
circle { return(CIRCLETOKEN); }
rectangle { return(RECTANGLETOKEN); }
\; { return(SEMICOLON); }
\, { return(COMMA); }
\( { return(LEFTPAREN); }
\) { return(RIGHTPAREN); }
[0-9]+ { yylval = atoi(yytext);
         return(NUMBER);
       }
[a-zA-Z][a-zA-Z0-9]* { yylval = strdup(yytext);
                       return(NAME);
                     }
\n /* ignore end of line */
[ \t]+ /* ignore white space */
%%
