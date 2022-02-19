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
    /* Mengembalikan value a + b */
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
    float result = 1;
    float i = 1;
    for (i=0; i < b; i++) {
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
    float i = 1;
    for (i=0; i < b; i++) {
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
    
    float a;
    float b;
    float c;
    float l;
    float r;

    printf("kalkulator luas area integral riemann\n");

    printf("integral terbatas persamaan y = ax^2 + bx + c\n");

    printf("masukkan nilai a\n");
    scanf("%f", &a);

    printf("masukkan nilai b\n");
    scanf("%f", &b);

    printf("masukkan nilai c\n");
    scanf("%f", &c);

    printf("masukkan batas kiri\n");
    scanf("%f", &l);

    printf("masukkan batas kanan\n");
    scanf("%f", &r);

    float x;
    float s;
    for(x = l; x < r; x++)
    {
        pPlus(&s, fTimes(1, fPlus(fPlus(fTimes(a, fPower(x, 2)), fTimes(b, x)), c)));
    }
    printf("%f", s);
}