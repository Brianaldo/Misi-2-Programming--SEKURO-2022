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
    *a = *a + b;
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
    *a = *a - b;
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
    *a = *a * b;
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
    *a = *a/b;
}

float fPower(float a, float b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
    float result = 1.0;
    int i;
    for(i = 0; i < b; i++)
    {
        result *= a;
    }
    return result;
}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    float result = 1.0;
    int i;
    for(i = 0; i < b; i++)
    {
        result *= *a;
    }
    *a = result;
}

void inputKoef(int n, float koef[])
{
    int i = 0;
    while(i <= n)
    {
        float temp = i;
        printf("Masukkan koefisien x berderajat %.0f: ", fMin(n,temp));
        scanf("%f", &koef[i]);
        pPlus(&temp, 1);
        i = temp;
        
    }
}

void printFx(int n, float koef[])
{
    int i = 0;
    printf("\nFungsi Anda: f(x) = ");
    while(i<=n)
    {
        float temp = i;
        
        if(i==fMin(n,1))
        {
            printf("%.1fx + ", koef[n-1]);
        }
        else if(i!=n)
        {
            printf("%.1fx^%.0f + ", koef[i], fMin(n,i)); 
        }
        else
        {
            printf("%.1f", koef[n]);
        }

        pPlus(&temp, 1);
        i = temp;
    }
    printf("\n\n");
}

float calcRiemann(int n, float koef[], float a, float b, int iterasi)
{
    int i;
    int j;
    float x;
    float dx = fDivide((fMin(b,a)),iterasi);
    float result = 0;

    i = 0;
    j = 0;
    x = a;
    while(i < iterasi)
    {
        float temp = i;
        float fx = 0;
        pPlus(&x,dx);
        j = 0;
        while(j<=n)
        {
            float temp2 = j;
            pPlus(&fx, fTimes(koef[j], fPower(x, fMin(n,j))));
            pPlus(&temp2, 1);
            j = temp2;   
        }
        
        pPlus(&result, fTimes(fx, dx));
        pPlus(&temp, 1);
        i = temp;
    }
    return result;
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */

    printf("Selamat datang di program Integral Riemann\n\n");
    printf("Masukkan derajat maksimum: ");
    int n;
    scanf("%d", &n);
    float koef[n];
    float a,b;
    int iterasi;
    float result;

    // Input koefisien fungsi polinom
    inputKoef(n, koef);

    // Print bentuk fungsi f(x)
    printFx(n, koef);

    //Input batas atas (a) batas bawah (b)    
    printf("Masukkan batas atas dan bawah\n");
    printf("Batas bawah: ");
    scanf("%f", &a);
    printf("Batas atas: ");
    scanf("%f", &b);

    // Input berapa banyak iterasi  (semakin tinggi semakin baik)
    printf("Masukkan jumlah iterasi: ");
    scanf("%d", &iterasi);

    // Menghitung integral Riemann
    result = calcRiemann(n, koef, a, b, iterasi);

    // Output hasil hitung integral Riemann
    printf("Hasil penjumlahaan riemann = %f", result);

    return 0;
}
