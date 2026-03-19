#include<stdio.h>
int main ()
 {
    int i,j,k=1,n,space;
    printf("enter the number of rows: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
     {
        for(space=n-i;space>n-1;space--)
         {
            printf(" ");
        }
        for(j=0;j<=i;j++)
         {
            if (j==0 || i==0)
                k=1;
            else
                k=k*(i-j+1)/j;
            printf("%d ",k);
        }
        printf("\n");
    }
    return 0;
}