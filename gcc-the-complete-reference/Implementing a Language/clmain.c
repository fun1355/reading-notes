/* clmain.c */
#include "clang.tab.h"
#include <stdio.h>
#include <string.h>
char colorname[30] = "black";
int x = 0;
int y = 0;
main()
{
    yyparse();
}
int yywrap()
{
    return(1);
}
void yyerror(const char *str)
{
    fprintf(stderr,"Clang: %s\n",str);
}
int setcolor(char *name)
{
    strcpy(colorname,name);
    return(0);
}
/* Save the x and y location of the
next figure to be drawn. */
int setlocation(int xloc,int yloc)
{
    x = xloc;
    y = yloc;
}
/* Draw a circle of the of the specified size and color
at the current location. */
int drawcircle(int radius)
{
    printf("Draw %s circle at (%d,%d) radius=%d\n",
        colorname,x,y,radius);
}
/* Draw a rectangle of the specified height, width, and color
at the current location. */
int drawrectangle(int height,int width)
{
    printf("Draw %s rectangle at (%d,%d) h=%d w=%d\n",
        colorname,x,y,height,width);
}
