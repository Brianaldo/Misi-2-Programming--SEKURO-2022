#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    /* Function tambah */
    /* Mengembalikan value a + b */
    return a+b;
}

void main(){
    printf("Hasil 4.5 + 3.5: %.2f\n", fPlus(4.5,3.5));
}

void pPlus(float *a, float b) {
    /* Procedure tambah */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a + b */
}

float fMin(float a, float b) {
    /* Function tambah */
    /* Mengembalikan value a + b */
    return a-b;
}

void main(){
    printf("Hasil 4.5 - 3.5: %.2f\n", fMin(4.5,3.5));
}

void pMin(float *a, float b) {
    /* Procedure kurang */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a - b */
}

float fTimes(float a, float b) {
    /* Function tambah */
    /* Mengembalikan value a + b */
    return a*b;
}

void main(){
    printf("Hasil 4.5 + 3.5: %.2f\n", fTimes(4.5,3.5));
}

void pTimes(float *a, float b) {
    /* Procedure kali */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
}

float fDivide(float a, float b) {
    /* Function tambah */
    /* Mengembalikan value a + b */
    return a/b;
}

void main(){
    printf("Hasil 4.5 + 3.5: %.2f\n", fDivide(4.5,3.5));
}

void pDivide(float *a, float b) {
    /* Procedure bagi */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
}

float fPower(float a, float b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
    return 0;
}
