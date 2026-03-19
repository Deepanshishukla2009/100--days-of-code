#include <stdio.h>
#include <math.h>
int isPrime(int n){
    if (n <= 1) return 0; ;
    for (int i = 2; i * i <= n; i ++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int power(int base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}
int isArmstrongRecursive(int n, int digits) {
    if (n == 0) return 0;
    int digit = n% 10;
    return power(digit, digits) + isArmstrongRecursive(n / 10, digits);
}
int ispalindromeRecursive(int n, int rev) {
    if (n == 0) return rev;
    return ispalindromeRecursive(n%10+rev*10,n/10);
}
int main() {
    int num, choice;
    printf("Enter any number: ");
    scanf("%d", &num);
    printf("Choose operation:\n");
    printf("1. Prime\n2. Armstrong\n3. Palindrome\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if (num < 0) {
                printf("Negative numbers cannot be prime.\n");
            } else if (isPrime(num)) {
                printf("%d is a Prime number.\n", num);
            } else {
                printf("%d is NOT a Prime number.\n", num);
            }
            break;

        case 2: {
            int digits = (num == 0) ? 1 : (int)log10(num) + 1;
            int result = isArmstrongRecursive(num, digits);
            if (result == num)
                printf("%d is an Armstrong number.\n", num);
            else
                printf("%d is NOT an Armstrong number.\n", num);
            break;
        }

        case 3: {
            int reversed = ispalindromeRecursive(num, 0);
            if (reversed == num)
                printf("%d is a Palindrome number.\n", num);
            else
                printf("%d is NOT a Palindrome number.\n", num);
            break;
        }

        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}
