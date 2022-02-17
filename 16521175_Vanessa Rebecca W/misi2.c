/* MISI 2 */
/* Vanessa Rebecca W - 16521175 */

#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    /* Function tambah */
    float hasil = a + b;
    /* Mengembalikan value a + b */
    return hasil;
}

void pPlus(float *a, float b) {
    /* Procedure tambah */
    *a += b;
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a + b */
}

float fMin(float a, float b) {
    /* Function kurang */
    float hasil = a - b;
    /* Mengembalikan value a - b */
    return hasil;
}

void pMin(float *a, float b) {
    /* Procedure kurang */
    *a -= b;
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a - b */
}

float fTimes(float a, float b) {
    /* Function kali */
    float hasil = a * b;
    /* Mengembalikan value a * b */
    return hasil;
}

void pTimes(float *a, float b) {
    /* Procedure kali */
    *a *= b;
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
}

float fDivide(float a, float b) {
    /* Function bagi */
    float hasil = a / b;
    /* Mengembalikan value a / b */
    return hasil;
}

void pDivide(float *a, float b) {
    /* Procedure bagi */
    *a /= b;
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
}

float fPower(float a, float b) {
    /* Function pangkat */
    int temp = a;
    for(int i=0; i<b; i++){
        a = a*temp;
    }
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
    return a;
}

void pPower(float *a, float b) {
    int temp = a;
    /* Procedure pangkat */
    for(int i=0; i<b; i++){
        *a*temp;
    }
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
}

float f_x(float x);

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    float sum =0;
    float x = 0;
    float l;

    printf("kalkulator integral menggunakan konsep Integral Riemann\n");
    printf("Oleh : Vanessa Rebecca W - 16521175\n");
    int a, b, n, deltax;
  
    printf("a: ");
    scanf("%d", &a);

    printf("b: ");
    scanf("%d", &b);

    printf("n: ");
    scanf("%d", &n);

    deltax = fDivide(fMin(b, a), n);

    for(int i=0; i<b; i++) {
        sum = fPlus(sum, (fTimes(x,x)));
        x = fPlus(deltax, x);
    }
    l = fTimes(deltax, sum);

    printf("\nnilai integral=%f\n",l);
    scanf("");
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */

    return 0;
}
