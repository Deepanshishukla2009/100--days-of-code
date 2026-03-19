#include<stdio.h>
#include<conio.h>
int main()
{
    int i,w=841,l=1189,t;
    for(i=1;i<=8;i++)
    {
        t=l;
        l=w;
        w=t/2;
        printf("\n A%d: %d x %d",i,w,l);
    }
    return 0;
}