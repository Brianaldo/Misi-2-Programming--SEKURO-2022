#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    return a+b;
    /* Function tambah */
    /* Mengembalikan value a + b */
}

void pPlus(float *a, float b) {
    *a += b;
    /* Procedure tambah */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a + b */
}

float fMin(float a, float b) {
    return a-b;
    /* Function kurang */
    /* Mengembalikan value a - b */
}

void pMin(float *a, float b) {
    *a -= b;
    /* Procedure kurang */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a - b */
}

float fTimes(float a, float b) {
    return a*b;
    /* Function kali */
    /* Mengembalikan value a * b */
}

void pTimes(float *a, float b) {
    *a *= b;
    /* Procedure kali */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
}

float fDivide(float a, float b) {
    return a/b;
    /* Function bagi */
    /* Mengembalikan value a / b */
}

void pDivide(float *a, float b) {
    *a /= b;
    /* Procedure bagi */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
}

float fPower(float a, float b) {
    float x = a;


    if (b == 0){
        a = 1;
    }
    else if (b<0){
        b *= -1;
        for (int i = 1; i<=(b-1);i++){
            a *= x;
        }
        a = (1 /a);

    }


    else{
        for (int i = 1; i<=(b-1);i++){
            a= a*x;
        }      
    }
    return a;

    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
}

void pPower(float *a, float b) {
        float x = *a;


    if (b == 0){
        *a = 1;
    }
    else if (b<0){
        b *= -1;
        for (int i = 1; i<=(b-1);i++){
            *a *= x;
        }
        *a = (1 / *a);

    }


    else{
        for (int i = 1; i<=(b-1);i++){
            *a= *a * x;
        }      
    }

    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
}

int main() {
    /* Integral Calculator by Right Riemann Sum*/
    /* Batasan: Derajat dari fungsi adalah whole number {0, 1, 2, ...} */
    /* Bentuk Fungsi : f(x) = ax^n + bx^(n-1) + cx^(n-2) + ... +  konstanta */
    
    double hasil = 0; //inisiasi nilai hasil
    float dx = 0.0018; //inisiasi nilai delta x yang digunakan

    printf("Masukkan derajat tertinggi fungsi:\n "); //input pangkat tertinggi fungsi
    unsigned long long int derajat;
    scanf("%llu", &derajat);
    derajat = fPlus(derajat,1); //inisiasi agar jumlah input = derajat+1

    printf("Masukkan batas atas integral:\n "); //input batas atas integral
    double b_atas;
    scanf("%lf", &b_atas);

    printf("Masukkan batas bawah integral:\n ");//input batas bawah integral
    double b_bawah;
    scanf("%lf", &b_bawah);


    for (unsigned long long int pangkat = derajat; pangkat > 0; pangkat--){
        
        
        unsigned long long int p = fMin(pangkat,1);
        printf("Masukkan koefisien x^(%llu) : \n", p); //input koefisien
        double koef;
        scanf("%lf", &koef);
        
        double t_sum = 0; //penjumlahan sementara
        double b = b_bawah; //inisiasi varaibel b sebagai nilai x setiap partisi
        
        while (b < b_atas){ //loop untuk analisis nilai setiap pangkat
            t_sum = fPlus (t_sum , fPower(b, p));
            b = fPlus(b, dx);

        }

        hasil = fPlus(hasil, fTimes(dx, fTimes(koef, t_sum))); //untuk setiap pangkat dilakukan penjumlahan sehingga jumlahan reimann ini dipartisi sesuai derajat dari variabelnya

    }
    printf("Hasil: %lf", hasil );


    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */

    return 0;
}