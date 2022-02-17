#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    /* Function tambah */
    /* Mengembalikan value a + b */
    return a + b;
}

void pPlus(float *a, float b) {
    /* Procedure tambah */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a + b */
    *a += b;
}

float fMin(float a, float b) {
    /* Function kurang */
    /* Mengembalikan value a - b */
    return a - b;
}

void pMin(float *a, float b) {
    /* Procedure kurang */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a - b */
    *a -= b;
}

float fTimes(float a, float b) {
    /* Function kali */
    /* Mengembalikan value a * b */
    return a * b;
}

void pTimes(float *a, float b) {
    /* Procedure kali */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
    *a *= b;
}

float fDivide(float a, float b) {
    /* Function bagi */
    /* Mengembalikan value a / b */
    return a / b;
}

void pDivide(float *a, float b) {
    /* Procedure bagi */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
    *a /= b;
}

float fPower(float a, float b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
    int c = 1;
    for (int i = 1; i <= b; i++){
        c = c * a;
    }
    return c;
}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    float c = *a;
    for(int i = 1; i<= b; i++){
        *a *= c;
    }
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
    int a, b, n;
    printf("Masukkan batas bawah (a) = ");
    scanf("%d", &a);
    printf("Masukkan batas atas (b) = ");
    scanf("%d", &b);
    printf("Masukkan nilai n = ");
    scanf("%d", &n);


    float dx = fDivide((fMin(b, a)),n);
    float hasil = 0;
    for (int i = 1; i <= fPlus(b,1); i++){
        float xi = fPlus(a,(fTimes(dx,fMin(i,1))));
        float f = fMin(4,xi); // Menghitung integral dari fungsi 4 - x
        hasil = fPlus(hasil,f);

    }
    float hasil_riemann = fTimes(hasil,dx);
    printf("Hasil integral riemann = %f ", hasil_riemann);


    return 0;
}
