#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    return a + b;
}

void pPlus(float *a, float b) {
    *a +=b;
}

float fMin(float a, float b) {
    return a -b;
}

void pMin(float *a, float b) {
    *a -=b;
}

float fTimes(float a, float b) {
    return a * b;
}

void pTimes(float *a, float b) {
   *a *= b;
}

float fDivide(float a, float b) {
    return a/b;
}

void pDivide(float *a, float b) {
    *a /= b;
}

float fPower(float a, float b) {
    if(b==0)
        return 1;
    float temp = 1;

    for(int i=0; i<b; i++){
        temp = temp*a;
    }
    return temp;
}

void pPower(float *a, float b) {
    float ans = 0;
    if(b<0) {
        b *= -1;
        ans = 1/fPower(*a,b);
    } 
    else
        ans = fPower(*a,b);
    printf("%f\n", ans) ;
}

int main() {
    int n = 0, i = 0;
    float sum = 0;
    float a =0, b=0, step = 0;

    printf("Kalkulator integral Riemann");
    printf("Input a, b, n, dan step: ");
    scanf("%f %f %d %f", &a, &b, &n, &step);
    for (i=0; i<n; i++){
        sum += fTimes((fPlus(a, step*1)), (fPlus(a,step * (i+1))));
    }
    printf("Sum = %f\n", sum * (fDivide(step, 2)));
    return 0;
}