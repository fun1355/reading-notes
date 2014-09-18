/* double.c */
#include <stdio.h>
int main(int argc,char *argv[])
{
    int array[2];
    array[0] = 150;
    int i = 0;
    asm("movl %1,%%eax; \
         shl %%eax;     \
         movl %%eax,%0;"
        :"=r"(array[i+1])
        :"r"(array[i])
        :"%eax");

    printf("array[0]=%d array[1]=%d\n",array[0],array[1]);

    return(0);
}