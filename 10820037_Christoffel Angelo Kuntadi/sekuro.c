#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    return a+b;
}

void pPlus(float *a, float b) {
   *a +=b ;
}

float fMin(float a, float b) {
    return a-b;
}

void pMin(float *a, float b) {
    *a -= b;
}

float fTimes(float a, float b) {
    return a*b;
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

float fPower(float a, int b) {
    int i = 0;
    float v = a;
    for (i=0;i<b;i++){
        v *= a ;        
    }
    return v;
}

void pPower(float *a, int b) {
    int i = 0;
    float v = *a;
    for (i=0;i<b;i++){
        *a *= v ;
    }
}

int main() {
    int N = 100;
    float i = 0;
    float a = -2; 
    float b = 2;
    float sum = 0;
    float y = 0;
    float p =0;
    float x =a;
    float z =0;
    p = fMin(b,a);
    p = fDivide(p,N);
    printf("Program integral Riemann dengan batas [-2,2] \n");
    printf("Program ini menghitung integral -x^2+4 \n"); 
    for (i = 0; i<N; i++){
        z = fTimes(x,x);
        y = fPlus(-z,4);
        z = fTimes(y,p);
        sum = fPlus(z,sum);
        x = fPlus(x,p);
    }
    printf("Hasil perhitungan integral diatas adalah = %f\n",sum);
    return 0;
}