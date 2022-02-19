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
    /* F.S. a menjadi a / b */
    *a /= b;
}

float fPower(float a, float b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
    float result = 1;
    for (int i = 1; i <= b; i++){
        result *= a;
    }
    return result;
}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    float result = 1;
    for (int i = 1; i <= b; i++){
        result *= *a;
    }
    *a = result;
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
    printf("=============== KALKULATOR INTEGRAL ===============");
    
    float bot, top, nPartition, deltaX, result, xi, suku;

    printf("\nbatas bawah: ");
    scanf("%f", &bot);
    
    printf("batas atas: ");
    scanf("%f", &top);
    
    printf("jumlah partisi: ");
    scanf("%f", &nPartition);
    
    deltaX = fDivide(fMin(bot,top), nPartition);

    for (int i = 1; i <= nPartition; i++) {
        xi = fTimes(i,deltaX);
        suku = (fPlus(bot, xi));
        /* Asumsi fungsi f(x) = 4x^2 + 1 */
        result += fTimes((fPower(suku,2)),4) + 1; 
    }

    printf("Hasil integral: %f\n", result);
    return 0;
}