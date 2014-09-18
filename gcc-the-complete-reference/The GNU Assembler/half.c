/* half.c */
#include <stdio.h>
int main(int argc,char *argv[])
{
    int a = 40;
    int b;
    asm("movl %1,%%eax; \
        shr %%eax;      \
        movl %%eax,%0;"
        :"=r"(b)
        :"r"(a)
        :"%eax");

    printf("a=%d b=%d\n",a,b);
    return(0);
}

