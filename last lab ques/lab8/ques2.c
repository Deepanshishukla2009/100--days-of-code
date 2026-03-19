#include <stdio.h>

#define SIZE 100

struct Employee {
    char name[50];
    float basicPay;
    float grossSalary;
};

int main() {
    struct Employee emp[SIZE];
    int i;

    for (i = 0; i < SIZE; i++) {
        printf("Enter name of employee %d: ", i + 1);
        scanf("%s", emp[i].name);

        printf("Enter basic pay of %s: ", emp[i].name);
        scanf("%f", &emp[i].basicPay);

        float DA = 0.52 * emp[i].basicPay;
        emp[i].grossSalary = emp[i].basicPay + DA;
    }
    for (i = 0; i < SIZE; i++) {
        printf("Name: %s\tGross Salary: %.2f\n", emp[i].name, emp[i].grossSalary);
    }

    return 0;
}