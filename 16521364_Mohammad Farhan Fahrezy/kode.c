/*Mohammad Farhan Fahrezy*/
/*16521364*/

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
    int i;
    for(i = 0; i < b; i++) 
    {
        result *= a;
    }
    return result;
}

void pPower(float *a, float b) {
    float result = 1;
    int i;
    for(i = 0; i < b; i++) 
    {
        result *= *a;
    }
    *a = result;
}

int main() {
    float a, b, n, d, result;
    result = 0;
    int i;
    
    printf("KALKULATOR INTEGRAL\n");
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("n: ");
    scanf("%f", &n);
    d = fDivide((fMin(b,a)), n);
    
    for (i = 1; i <= n; i++) {
        result += fTimes((fPower((fPlus(a, (fTimes(i,d)))),3)),5); /* y =5x^3 */
    }
    printf("The result is: %f\n", result);
    return 0;
}