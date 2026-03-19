#include<stdio.h>
    int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

void ispascaltriangle(int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < rows-i-1; j++)
            printf(" ");
        for(int j = 0; j <= i; j++) {
            int value = factorial(i)/(factorial(j)*factorial(i-j));
            printf("%d ", value);
        }
        printf("\n");
    }
}
    void isrightangletriangle(int rows){
        for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
}
   void isinvertedtriangle(int rows){
     for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
   }
   void pyramidtriangle(int rows){
     for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++)
            printf(" ");
        for (int k = 1; k <= 2 * i - 1; k++)
            printf("*");
        printf("\n");
    }
   }
   int main(){
    int rows,choice;
    printf("enter no. of rows:");
    scanf("%d",&rows);
    if(rows<1 || rows>10){
        printf("enter no. of rows between 1 to 10\n");
    }
    else{
         printf("\nChoose a triangle pattern to print:\n");
         printf("1. pascal triangle\n");
         printf("2. rightangle triangle\n");
         printf("3. inverted triangle\n");
         printf("4. pyramid triangle\n");
         printf("enter your choice 1 to 4:");
         scanf("%d",&choice);
    }
    switch(choice){
        case 1: ispascaltriangle(rows);break;
        case 2: isrightangletriangle(rows);break;
        case 3: isinvertedtriangle(rows);break;
        case 4: pyramidtriangle(rows);break;
        default:
        printf("invalid choice\n");
    }
    return 0;
   }
