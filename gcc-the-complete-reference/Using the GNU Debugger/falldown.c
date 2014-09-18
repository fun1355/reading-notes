/* falldown.c */
#include <stdio.h>
char** nowhere;
void setbad();
int main(int argc,char *argv[])
{
    setbad();
    printf("%s\n",*nowhere);
}
void setbad()
{
    nowhere = 0;
    *nowhere = "This is a string\n";
}
