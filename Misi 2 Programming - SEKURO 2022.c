#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    return a + b;
}

void pPlus(float *a, float b) {
    pPlus(a,b);
    *a += b;
    printf("%f", &a);
}

float fMin(float a, float b) {
    /* Function kurang */
    return a - b;
}

void pMin(float *a, float b) {
    /* Procedure kurang */
    pMin(a,b);
   *a -= b;
}

float fTimes(float a, float b) {
    /* Function kali */
    return a * b;
}

void pTimes(float *a, float b) {
    /* Procedure kali */
    pTimes(a,b);
    *a *= b;
}

float fDivide(float a, float b) {
    /* Function bagi */
    return a / b;
}

void pDivide(float *a, float b) {
    /* Procedure bagi */
    pDivide(a,b);
    *a /= b;
}

float fPower(float a, float b) {
    /* Function pangkat */
    return a*a;
}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    pPower(a,b);
    *a *= *a;
}

int main() {
    float *x,y;
    printf("Masukkan x  dan y: ");
    scanf("%d %d", &x, &y);
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    pPower(x,y);                //x^y
    pPlus(&pPower,fTimes(y,y));       //x^y + y*y
    
    return 0;
}
