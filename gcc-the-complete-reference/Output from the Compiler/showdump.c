/* showdump.c */
#include <stdio.h>
int a = 44;
static int b = 22;
int main(int argc,char *argv[])
{
    if(a > b) {
        b = a;
    } else {
        a = b;
    }
    return 0;
}
