#include<stdio.h>
#include<conio.h>
int main ()
 {
    int i, j, k = 1,n,space;
    printf("enter the number of rows: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
     {
        for(space=n-i;space>0;space--)
         {
            printf(" ");
        }
        for(j=1;j<=i;j++) 
        {
            printf("%d ",k);
            k++;
        }
        printf("\n");
    }
    return 0;
}