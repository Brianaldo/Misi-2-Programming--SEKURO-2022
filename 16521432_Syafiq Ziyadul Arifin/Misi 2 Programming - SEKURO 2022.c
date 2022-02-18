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
    int i; float c = a;
    if (b == 0) {
        return 1;
    } else {
        for (i = 1; i < b; i++) {
            a *= c;
        }
        return a;
    }
}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    int i; float c = 1;
    if (b == 0) {
        *a = 1;
    } else {
        for (i = 0; i < b; i++) {
            c *= *a;
        }
        *a = c;
    }
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
    int derajatMax;
    float a, b, n, x, y, z;
    float koef[10], deltaX, riemann;
    int i, j;

    printf("Masukkan derajat polinom f(x) terbesar: ");
    scanf("%d", &derajatMax);

    for (i = 0; i <= derajatMax; i++) {
        z = fMin(derajatMax, i);
        printf("Masukkan nilai koefisien pangkat %d: ", (int)z);
        scanf("%f", &koef[i]);
    }

    printf("Masukkan batas bawah (x0): ");
    scanf("%f", &a);
    printf("Masukkan batas atas (xn): ");
    scanf("%f", &b);
    printf("Masukkan jumlah partisi (n): ");
    scanf("%f", &n);

    deltaX = fDivide(fMin(b, a), n);

    for (i = 0; i <= n; i++) {
        x = 0;
        for (j = 0; j <= derajatMax; j++) {
            z = fMin(derajatMax, j);
            y = fTimes(fPower(fTimes(deltaX, i), z), koef[j]);
            x = fPlus(x, y);
        }
        if (i == 0 || i == n) {
            riemann = fPlus(riemann, x);
        } else {
            riemann = fPlus(riemann, fTimes(x, 2));
        }
    }

    riemann = fDivide(fTimes(riemann, deltaX), 2);
    printf("\nHasil riemannya adalah %f", riemann);
}
