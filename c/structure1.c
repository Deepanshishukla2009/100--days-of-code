#include <stdio.h>
#include <string.h>

struct employee {
   char firstname[32];
   char lastname[32];
   int employee_id;
   int age;
   float salary;
} emp1;

int main(void) {
   printf("enter first name: ");
   scanf("%s", emp1.firstname);

   printf("enter last name: ");
   scanf("%s", emp1.lastname);

   printf("enter your employee id: ");
   scanf("%d", &emp1.employee_id);

   printf("enter your age: ");
   scanf("%d", &emp1.age);

   printf("enter your salary: ");
   scanf("%f", &emp1.salary);

   printf("your firstname is: %s\n", emp1.firstname);
   printf("your lastname is: %s\n", emp1.lastname);
   printf("your employee id is: %d\n", emp1.employee_id);
   printf("your age is: %d\n", emp1.age);
   printf("your salary is: %.2f\n", emp1.salary);

   return 0;
}
