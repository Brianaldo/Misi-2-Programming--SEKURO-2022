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
    float c = 1;
    for(int i = 1; i < b; i++){
        c = c * a;
    }
    return c;
}
void pPower(float *a, float b){
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    float c = *a;
    for(int i = 1; i < b; i++){
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
    float f = 0;
    float hasil_Riemann, xi;
    printf("Program Kalkulator Integral Riemann Kiri\n");
    printf("Masukkan nilai dari batas atas(b) = ");
    scanf("%d", &b);
    printf("Masukkan nilai dari batas bawah(a) = ");
    scanf("%d", &a);
    printf("Masukkan nilai n = ");
    scanf("%d", &n);
    float konst = fDivide(fMin(b,a), n);

    for(int i = 1; i <= n; i++){
    //Menghitung integral dengan fungsi x + 3
        xi = fPlus(a, (fTimes(fMin(i, 1), fDivide(fMin(b, a), n))));
        f = fPlus(f, fPlus(xi, 3)); //Menghitung nilai integral dengan fungsi f(x) = x + 3
    }
    hasil_Riemann = fTimes(konst, f);
    printf("%f", hasil_Riemann);

    return 0;
}
