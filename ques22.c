#include<stdio.h>
#include<conio.h>
int main()
{
    float sp,cp,profit_per,loss_per;
    printf("enter cost price:");
    scanf("%f",&cp);
    printf("enter selling price:");
    scanf("%f",&sp);
    if(sp>cp)
    {
        profit_per=((sp-cp)/cp)*100;
        printf("profit percentage=%.2f%%\n",profit_per);
    }
    else if(cp>sp)
    {
        loss_per=((cp-sp)/cp)*100;
        printf("loss percentage=%.2f%%\n",loss_per);
    }
    else
    {
        printf("no profit no loss\n");
    }
    return 0;
}