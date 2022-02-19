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
    int i;
    float A = 1;
    for (i = 0; i < b; i++) {
        A *= a;
    }
    return A;
}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    int i;
    float A = 1;
    for (i = 0; i < b; i++) {
        A *= *a;
    }
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */


    // Kalkulator Riemann Kanan
    int D, a, b, n, delta_x, i, j;
    /*
    D = derajat terbesar dari masukan fungsi
    a = batas bawah
    b = batas atas
    n = jumlah partisi
    delta x = (b-a)/n
    */

    printf("Derajat terbesar dari fungsi = ");
    scanf("%d", &D);

    printf("batas bawah = ");
    scanf("%d", &a);

    printf("batas atas = ");
    scanf("%d", &b);

    printf("jumlah partisi = ");
    scanf("%d", &n);

    delta_x = fDivide(fMin(b, a), n);

    // isi array xi[n] dengan x0 sampai xn
    float xi[n];
    xi[0] = b;
    for (i = 1; i < n+1; i++) {
        xi[i] = fMin((xi[i-1]), delta_x);
    }

    // isi array k[D] dengan input koefisien dari setiap derajat
    float k[D];
    for (i = 0; i < D+1; i++) {
        printf("Koefisien pada derajat %d = ", D-i);
        scanf("%f", &k[i]);
    }

    // hitung jumlah dari semua F(xi)
    float sum_F = 0;
    i = 0;
    while (i < n) {
        j = 0;
        while (j < D+1) {
            sum_F = sum_F + fTimes(k[j], fPower(xi[i], fMin(D, j)));
            j += 1;
        }
        i += 1;
    }
    
    // hitung hasil integral rieman
    // sum Riemann = delta x * sum F(x)
    float sum_R = delta_x * sum_F;
    printf("Hasil Integral Riemann = %f", sum_R);

    return 0;
}

