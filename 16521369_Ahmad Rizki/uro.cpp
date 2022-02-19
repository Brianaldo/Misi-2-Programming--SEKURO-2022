#include <stdio.h>
#include <stdbool.h>
# include <math.h>

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
    return pow(a, b);
}

void pPower(float *a, float b) {
    *a = pow(*a, b);
}

int main() {
    float a = 0, b = 0, step = 0;
    int n = 0, i = 0;
    float sum = 0;
    printf("Integral calculator with riemann sum with input from user\n");
    printf("Input a, b, n, and step: ");
    scanf("%f %f %d %f", &a, &b, &n, &step);
    for (i = 0; i < n; i++) {
        sum += fPlus(a, step * i) * fPlus(a, step * (i + 1));
    }
    printf("Sum = %f\n", sum * step / 2);
    return 0;
    
}