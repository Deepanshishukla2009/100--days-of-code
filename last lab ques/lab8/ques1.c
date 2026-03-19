#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex readComplex() {
    Complex c;
    printf("Enter real part: ");
    scanf("%f", &c.real);
    printf("Enter imaginary part: ");
    scanf("%f", &c.imag);
    return c;
}

void writeComplex(Complex c) {
    printf("Complex number: %.2f %c %.2fi\n", c.real, (c.imag >= 0) ? '+' : '-', (c.imag >= 0) ? c.imag : -c.imag);
}

Complex addComplex(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex subtractComplex(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

int main() {
    Complex num1, num2, sum, diff;

    printf("Enter first complex number:\n");
    num1 = readComplex();

    printf("Enter second complex number:\n");
    num2 = readComplex();

    sum = addComplex(num1, num2);
    diff = subtractComplex(num1, num2);
    
    printf("First ");
    writeComplex(num1);

    printf("Second ");
    writeComplex(num2);

    printf("Sum ");
    writeComplex(sum);

    printf("Difference ");
    writeComplex(diff);

    return 0;
}