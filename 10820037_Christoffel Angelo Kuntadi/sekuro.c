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
    for (i=0;i<b-1;i++){
        v *= a ;        
    }
    return v;
}

void pPower(float *a, int b) {
    int i = 0;
    float v = *a;
    for (i=0;i<b-1;i++){
        *a *= v ;
    }
}

int main()
{
    int a,b,p,i;
    printf("Program ini menghitung integral (ox^p)+q dengan o,p dan q adalah input dari user \n"); 
    printf("Masukkan batas [a,b]: \n");
    printf("a : ");
    scanf("%d", &a);
    printf("b : ");
    scanf("%d", &b);
    float z,o,q,y,sum;
    int N = 1000;
    z =b-a;
    z =z/N;
    float x =a;
    printf("o : ");
    scanf("%f", &o);
    printf("p : ");
    scanf("%d", &p);
    printf("q : ");
    scanf("%f", &q);
    for (i = 0; i<N; i++){
        y = fPower(x,p);
        y = fTimes(y,o);
        y = fPlus(y,q);
        y = fTimes(y,z);
        sum = fPlus(y,sum);
        x = fPlus(x,z);
    }
    printf("Hasil perhitungan integral diatas adalah = %f\n",sum);
    return 0;
}
