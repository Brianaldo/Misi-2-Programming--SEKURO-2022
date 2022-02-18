/* Nama : Ahmad Nadil */
/* NIM : 16521516 */

#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    /* Function tambah */
    /* Mengembalikan value a + b */
    return a+b;
}

void pPlus(float *a, float b) {
    /* Procedure tambah */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a + b */
    *a = *a + b;
}

float fMin(float a, float b) {
    /* Function kurang */
    /* Mengembalikan value a - b */
    return a-b;
}

void pMin(float *a, float b) {
    /* Procedure kurang */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a - b */
    *a = *a - b;
}

float fTimes(float a, float b) {
    /* Function kali */
    /* Mengembalikan value a * b */
    return a*b;
}

void pTimes(float *a, float b) {
    /* Procedure kali */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
    *a = *a * b;
}

float fDivide(float a, float b) {
    /* Function bagi */
    /* Mengembalikan value a / b */
    return a/b;
}

void pDivide(float *a, float b) {
    /* Procedure bagi */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
    *a = *a / b;
}

float fPower(float a, float b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
    float hasil = 1;
    int i;
    for (i = 0; i < b; i++) {
        hasil = hasil * a;
    }
    return hasil;
}
void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    float hasil = 1;
    int i;
    for (i = 0; i < b; i++) {
        hasil = hasil * *a;
    }
    *a = hasil;
}
// Fungsi Riemann Trapeozoid
float riemannTrapezoid(float a, float b, float h, float (*f)(float, float)) {
    /* Fungsi riemann trapezoid */
    /* Mengembalikan nilai integral dari fungsi f dengan batas a, b, dan h */
    /* a adalah batas bawah, b adalah batas atas, h adalah tinggi trapesium */
    float hasil = 0;
    float x;
    for (x = a; x < b; x = x + h) {
        hasil = fPlus(hasil,f(x, h));
    }
    hasil = fPlus(hasil,f(a, h));
    hasil = fPlus(hasil, f(b,h));
    hasil = fTimes(hasil,h);
    hasil = fDivide(hasil,2);
    return hasil;
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
    
    /* Fungsi dan Prosedur */
    /* Fungsi: fPlus, fMin, fTimes, fDivide, fPower */
    /* Prosedur: pPlus, pMin, pTimes, pDivide, pPower */
    
    /* Tes Fugsi dan Prosedur */
    printf("========================================================\n");
    printf("Kalkulator Sederhana\n");
    printf("========================================================\n");

    /* Input */
    float a, b;
    printf("Masukkan Nilai a: ");
    scanf("%f", &a);
    printf("Masukkan Nilai b: ");
    scanf("%f", &b);

    /* Output */
    printf("Hasil %f + %f : %f\n", a, b, fPlus(a, b));
    printf("Hasil %f - %f : %f\n", a, b, fMin(a, b));
    printf("Hasil %f * %f : %f\n", a, b, fTimes(a, b));
    printf("Hasil %f / %f : %f\n", a, b, fDivide(a, b));
    printf("Hasil %f ^ %f : %f\n", a, b, fPower(a, b));

    /* Kalkulator Riemann */
    float h;
    int n;
    printf("Masukkan batas bawah: ");
    scanf("%f", &a);
    printf("Masukkan batas atas: ");
    scanf("%f", &b);
    printf("Masukkan tinggi trapesium: ");
    scanf("%f", &h);
    printf("Hasil Integral Riemann Trapezoid: %f\n", riemannTrapezoid(a, b, h, fPower));
    printf("========================================================\n");
    return 0;
}