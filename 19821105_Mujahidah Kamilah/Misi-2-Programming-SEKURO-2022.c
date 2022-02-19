#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    /* Function tambah */
    /* Mengembalikan value a + b */
    return (a + b);
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
    *a * b;
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
    *a / b;
}

int fPower(int a, int b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
    int hasil, i;
    hasil = 1;
    for (i=1; i<=b; i++) {
        hasil = hasil * a;
    }
    return hasil;
}

void pPower(int *a, int b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    int hasil, i;
    hasil = 1;
    for (i=1; i<=b; i++) {
        hasil = hasil * *a;
    };
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
    int a, b, count, x, i, A[100], B[100], C[100], n, f, j, sum, d;
    char hasil[100];
    printf("Masukkan batas integral\n");
    printf("Masukkan batas awal (a): ");
    scanf("%d", &a);
    printf("Masukkan batas awal (b): ");
    scanf("%d", &b);
    
    printf("\nMasukkan pangkat tertinggi x di dalam fungsi : "); scanf("%d", &n);
    for (i=n; i>=0; i--) {
        printf("Koef x^%d = ", i); scanf("%d", &A[i]);
    }

    for (i=n; i>=0; i--) {
        B[i+1] = fDivide(A[i], (i+1));
        C[i+1] = (B[i+1]*(fPower(b, (i+1))))-(B[i+1]*(fPower(a, (i+1))));
    }

    sum = 0;
    for (i=n+1; i>=1; i--) {
        sum = fPlus(sum, C[i]);
    }

    printf("\nMaka hasil integralnya adalah: \n");

    for (i=n+1; i>=1; i--) {
        printf("pangkat %d = %dx^%d\n", (i), B[i], (i));
    }

    printf("\nBila dimasukkan batasnya, maka hasilnya adalah: \n");
    printf("%d", sum);

    return 0;
    /* Kalkulator yang saya buat ini belum sempurna, 
    karena hanya bisa menghasilkan koefisien integral yang bulat (int)
    dan kalkulator integral saya belum dapat menggunakan konsep integral Riemann,
    mohon maaf atas kekurangannya :"*/
}
