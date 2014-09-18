/* looper.c */
#include <stdio.h>
void goaround(int);
int main(int argc,char *argv[])
{
    printf("started\n");
    goaround(20);
    printf("done\n");
}
void goaround(int counter)
{
    int i = 0;
    while(i < counter){
        if(i++ == 17)
          i = 10;
    }
}

