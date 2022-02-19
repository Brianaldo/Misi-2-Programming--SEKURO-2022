#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    float hasil;
    hasil=a+b;
    return hasil;
}


void pPlus(float *a, float b) {
    printf("Angka pertama = ");
    scanf("%f",&a);
    printf("Angka kedua = ");
    scanf("%f",&b);
    printf("Hasil =%f",fPlus(*a,b));
}

float fMin(float a, float b) {
    float hasil;
    hasil=a-b;
    return hasil;
}

void pMin(float *a, float b) {
    printf("Angka pertama = ");
    scanf("%f",&a);
    printf("Angka kedua = ");
    scanf("%f",&b);
    printf("Hasil =%f",fMin(*a,b));
}

float fTimes(float a, float b) {
    float hasil;
    hasil=a*b;
    return hasil;
}

void pTimes(float *a, float b) {
    printf("Angka pertama = ");
    scanf("%f",&a);
    printf("Angka kedua = ");
    scanf("%f",&b);
    printf("Hasil =%f",fTimes(*a,b));
}

float fDivide(float a, float b) {
    float hasil;
    hasil=a/b;
    return hasil;
}

void pDivide(float *a, float b) {
    printf("Angka pertama = ");
    scanf("%f",&a);
    printf("Angka kedua = ");
    scanf("%f",&b);
    printf("Hasil =%f",fDivide(*a,b));
}

float fPower(float a, float b) {
   float count, hpang;
    count = 0;
    hpang = 1;

    for (count=0; count<b; count++){
        hpang = hpang*a;
    }
    return hpang;
}

void pPower(float *a, float b) {
    printf("Angka basis = ");
    scanf("%f", &a);
    printf("Pangkat = ");
    scanf("fd", &b);
    printf("Hasil = %d", fPower(*a,b));
}

double f(double x){
    return 3*x*x + 2*x +1;
} 
int main() {
    int a,b,c, menu,dasar,n,i;
    double atas,bawah,h,sum,integral,x;
    //Tampilan menu:
    printf("Hallo\n");
    printf("Ini adalah kalkulator integral rieman\n");
    printf("-----------------------------------------\n");
    printf("Masukkan batas atas = ");
    scanf("%lf",&atas);
    printf("Masukkan batas bawah = ");
    scanf("%lf",&bawah);
    printf("Masukkan panjang sub interval = ");
    scanf("%d",&n);
    h=(atas-bawah)/n;
    sum = 0;
    for(i=1;i<n;i++){
        x = bawah+i*h;
        sum = sum +f(x);
    }
    integral = h/2.0*(f(bawah)+2*sum+f(atas));
    printf("Hasil Integral = %lf",integral); 
    return 0;
}
