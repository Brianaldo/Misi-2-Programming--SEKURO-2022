#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    return a + b;
}

void pPlus(float *a, float b) {
    *a += b;
}

float fMin(float a, float b) {
    return a - b;
}

void pMin(float *a, float b) {
    *a -= b;
}

float fTimes(float a, float b) {
    return a * b;
}

void pTimes(float *a, float b) {
    *a *= b;
}

float fDivide(float a, float b) {
    return a / b;
}

void pDivide(float *a, float b) {
    *a /= b;
}

float fPower(float a, float b) {
    // power function
    float result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

void pPower(float *a, float b) {
    // power prosedure
    float result = 1;
    for (int i = 0; i < b; i++) {
        result *= *a;
    }
    *a = result;
}

int main() {
    // integral calculator with riemann sum
    float a, b, n, h, sum;
    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter n: ");
    scanf("%f", &n);
    h = (b - a) / n;
    sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += fPlus(a, i * h);
    }
    printf("The result is: %f\n", sum * h);
    return 0;
}
