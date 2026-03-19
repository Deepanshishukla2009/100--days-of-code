#include<stdio.h>
#include<conio.h>
int main() 
{
    int num1, num2, result;
    char op;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter an operator (+, -, *, /, %%): ");
    scanf(" %c", &op);
    printf("Enter second number: ");
    scanf("%d", &num2);
    switch (op) 
    {
        case '+':
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case '/':
            if (num2 != 0)
             {
                result = num1 / num2;
                printf("Result: %d\n", result);
            } 
            else
             {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case '%':
            if (num2 != 0)
             {
                result = num1 % num2;
                printf("Result: %d\n", result);
            } 
            else
             {
                printf("Error: Modulo by zero is not allowed.\n");
          }
            break;
        default:
            printf("Error: Invalid operator.\n");
    }
    return 0;
}
