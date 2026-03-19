#include <stdio.h>
void userInfo(char name[], int *age) {
    printf("enter your name: ");
    scanf("%s", name);
    printf("enter your age: ");
    scanf("%d", age);
}
int main() {
    char name[50];
    int age;
    userInfo(name, &age); 
    printf("your name : %s\n",name);
    printf("your age:%d\n",age);
    return 0;
}
