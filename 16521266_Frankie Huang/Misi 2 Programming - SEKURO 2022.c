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

int pascal(int r, int c)
{
    /* Mengembalikan bilangan pascal pada baris ke-r dan kolom ke-c. Penomoran dimulai dari 0 */
    if (c == 0 || c == r)
        return 1;
    else
        return (fPlus(pascal((r-1), (c-1)), pascal((r-1), c)));
}

float totalSum(float coefficient, float lowerBound, float upperBound, int n)
{
    /* Mengembalikan nilai penjumlahan total dari suatu koefisien pangkat x */
    float sum = 0;

    for (int i = n; i >= 0; i--)
    {
        pPlus(&sum, fDivide(fTimes(fTimes(fTimes(fPower(lowerBound, n-i), pascal(n, i)), coefficient), fPower((upperBound-lowerBound), i+1)), (i+1)));
    }

    return sum;

}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */


    float lowerBound, upperBound, sum = 0;
    int n;

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
            printf("Koefisien pangkat 1\t\t= ");
        else if (n-i == 0)
            printf("Nilai konstanta\t\t\t= ");
        else
            printf("Koefisien pangkat %d\t\t= ", n-i);
        scanf("%f", &c[i]);
    }

    for (int i = 0; i <= n; i++)
    {
        pPlus(&sum, totalSum(c[i], lowerBound, upperBound, n-i));
    }

    printf("Nilai integral\t\t= %f", sum);

    return 0;
}
