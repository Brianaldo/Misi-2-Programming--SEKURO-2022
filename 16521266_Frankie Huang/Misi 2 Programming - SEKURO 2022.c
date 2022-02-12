#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    /* Function tambah */
    /* Mengembalikan value a + b */
    return a+b;
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
    return a-b;
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
    return a*b;
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
    return a/b;
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

    return (b == 0)? 1 : fPower(a, b-1)*a;
}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    while (b > 0)
    {
        *a *= *a;
        b--;
    }
}

// Mengembalikan nilai hasil kali koefisien suatu penjumlahan riemann
float pascal(float coefficient, float lowerBound, float upperBound, int n)
{
    // Tabel segitiga pascal
    int p[11][11] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0},
                     {1, 4, 6, 4, 1, 0, 0, 0, 0, 0, 0},
                     {1, 5, 10, 10, 5, 1, 0, 0, 0, 0, 0},
                     {1, 6, 15, 20, 15, 6, 1, 0, 0, 0, 0},
                     {1, 7, 21, 35, 35, 21, 7, 1, 0, 0, 0},
                     {1, 8, 28, 56, 70, 56, 28, 8, 1, 0, 0},
                     {1, 9, 36, 84, 126, 126, 84, 36, 9, 1, 0},
                     {1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1}};

    float sum = 0;

    for (int i = n; i >= 0; i--)
    {
        pPlus(&sum, fDivide(fTimes(fTimes(fTimes(fPower(lowerBound, n-i), p[n][i]), coefficient), fPower((upperBound-lowerBound), i+1)), (i+1)));
    }

    return sum;

}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */


    /*
    Batas atas derajat koefisien integral riemann adalah 10
    Untuk suatu fungsi ax^n+bx^(n-1)+cx^(n-2)+...+k dengan batas atas x dan batas bawah y, jumlah limit riemann dapat didefinisikan sebagai
    (1/n)*p(a,n,n)*(x-y)^n + (1/(n-1))*p(a,n-1,n)*(x-y)^(n-1)+ ....+
    dengan fungsi p(a, i, n) mengembalikan koefisien segitiga pascal ke (n+1) pada posisi ke-i dari kiri.
    */

    // Deklarasi variabel
    float lowerBound, upperBound, sum = 0;
    int n;

    // Input nilai dan deklarasi variabel pangkat
    printf("Batas bawah integral\t\t= ");
    scanf("%f", &lowerBound);
    printf("Batas atas integral\t\t= ");
    scanf("%f", &upperBound);
    printf("Koefisien pangkat tertinggi\t= ");
    scanf("%d", &n);

    float c[n+1];

    for (int i = 0; i <= n; i++)
    {
        if (n-i == 1)
            printf("Koefisien pangkat 1\t= ");
        else if (n-i == 0)
            printf("Nilai konstanta\t\t= ");
        else
            printf("Koefisien pangkat %d\t= ", n-i);
        scanf("%f", &c[i]);
    }

    // Loop untuk menjumlahkan nilai sum
    for (int i = 0; i <= n; i++)
    {
        pPlus(&sum, pascal(c[i], lowerBound, upperBound, n-i));
    }

    // Output nilai
    printf("Nilai integral\t\t= %f", sum);

    return 0;
}
