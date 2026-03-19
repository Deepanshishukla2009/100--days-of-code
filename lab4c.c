#include<stdio.h>
#include<conio.h>
int main()
{
    int x1,y1,x2,y2,x3,y3;
    float area;
    printf("enter coordinates of first point:");
    scanf("%d%d",&x1,&y1);
    printf("enter coordinates of second point:");
    scanf("%d%d",&x2,&y2);
    printf("enter coordinates of third point:");
    scanf("%d%d",&x3,&y3);
    area=(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2;
    if(area==0)
    {
        printf("points are collinear");
    }
    else
    {
        printf("points are not collinear");
    }
    return 0;
}