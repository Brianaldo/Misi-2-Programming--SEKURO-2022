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
    float result = 1;
    for(int i = 0; i < b; i++) 
    {
        result *= a;
    }
    return result;
}

void pPower(float *a, float b) {
    float result = 1;
    for(int i = 0; i < b; i++) 
    {
        result *= *a;
    }
    *a = result;
}

int main() {
    printf("KALKULATOR INTEGRAL\n");
    float a, b, n, d, result;
    printf("a: "); /* batas bawah */
    scanf("%f", &a);
    printf("b: "); /* batas atas */
    scanf("%f", &b);
    printf("n: "); /* jumlah partisi */
    scanf("%f", &n);
    d = fDivide((fMin(b,a)), n); /* dx partisi */
    result = 0;
    for (int i = 1; i <= n; i++) {
        result += fTimes((fPower((fPlus(a, (fTimes(i,d)))),2)),3); /* y =3x^2 */
    }
    printf("The result is: %f\n", result);
    return 0;
}
