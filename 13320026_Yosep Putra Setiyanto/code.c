#include <stdio.h>
#include <stdbool.h>
float fPlus (float a, float b);
float fMin (float a, float b);
float fTimes (float a, float b);
float fDivide (float a, float b);
float fPower (float a, float b);
void integ ();

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

float fPower(float a, float b) {
    float x=1;
    int i;
    for( i=0; i<b ; i = i + 1){
        x=x*a;
    }
    return x;
}

void integ(){
        int n;
        int i;
        int batas_bawah;
        int batas_atas;
        float reslt=0;
        float j;
        printf("Masukan Derajat Polinomial =   ");
        scanf("%d",&n);
        
        float a[n];
        printf("Masukan Konstanta dalam Polinomial\nKeterangan \n a0 adalah konstanta paling akhir dalam polinomial\n");
        for( i=0; i<=n ; i = i + 1){
            printf("input a%d =  ",i);
            scanf ("%f",&a[i]);
        }   
        printf("masukan batas-batas integral (batas bawah space batas atas) \n contoh 0 5 \n    =   ");
        scanf("%d%d",&batas_bawah, &batas_atas);
        for( j=batas_bawah; j<=batas_atas ; j = j + 0.0001){
            for( i=0; i<=n ; i = i + 1){
                reslt=reslt+(a[i]*fPower(j,i)*0.0001);
           }   
        }
        printf("Hasil Integral adalah %.2f",reslt);
}

int main(){
    printf("wellcome to integral calculator :) \n\n");
    integ();
    }