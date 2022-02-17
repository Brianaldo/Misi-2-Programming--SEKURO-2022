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

    float aPowb;

    aPowb = a;

    for (int i = 2; i <= b; i++) {
        pTimes(&aPowb, b);
    }

    return aPowb;

}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */

    float aPowb;

    aPowb = *a;

    for (int i = 2; i <= b; i++) {
        pTimes(&aPowb, b);
    }

    *a = aPowb;

}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */

    return 0;
}
