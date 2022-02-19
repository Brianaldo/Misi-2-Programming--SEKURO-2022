#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    return a += b;
    /* Function tambah */
    /* Mengembalikan value a + b */
}

void pPlus(float *a, float b) {
    *a += b;
    /* Procedure tambah */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a + b */
}

float fMin(float a, float b) {
    return a -= b;
    /* Function kurang */
    /* Mengembalikan value a + b */
}

void pMin(float *a, float b) {
    *a -= b;
    /* Procedure kurang */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a - b */
}

float fTimes(float a, float b) {
    return a *= b;
    /* Function kali */
    /* Mengembalikan value a * b */
}

void pTimes(float *a, float b) {
    *a *= b;
    /* Procedure kali */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
}

float fDivide(float a, float b) {
    return a /= b;
    /* Function bagi */
    /* Mengembalikan value a / b */
}

void pDivide(float *a, float b) {
    *a /= b;
    /* Procedure bagi */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
}

float fPower(float a, float b) {
    float c = a;
    a = 1;
    if (b < 0){
        b = -b;
        for (int i = 0; i < b; i++){
            a *= c;
        }
    }
    else {
        for (int i = 0; i < b; i++){
            a *= c;
        }
    }
    return a;
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
}

void pPower(float *a, float b) {
    float c = *a;
    *a = 1;
    if (b < 0){
        b = -b;
        for (int i = 0; i < b; i++){
            *a *= c;
        }
    }
    else {
        for (int i = 0; i < b; i++){
            *a *= c;
        }
    }
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
}

int main() {
    printf("--- INTEGRAL RIEMANN KIRI ---\n");

    float hasil = 0;

    int derajat;
    printf("Masukkan derajat : ");
    scanf("%d", &derajat);

    int banyakKoef = fPlus(derajat, 1);
    float koef[banyakKoef];
    printf("Masukkan koefisien setiap suku (a1, a2, a3...)\n");
    for (int i = 0; i < banyakKoef; i++){
        printf("a%d = ", i);
        scanf("%f", &koef[i]);
    }

    int batas0;
    printf("Masukkan batas bawah : ");
    scanf("%d", &batas0);
    
    int batas1;
    printf("Masukkan batas atas : ");
    scanf("%d", &batas1);

    int banyakPartisi;
    printf("Masukkan jumlah partisi : ");
    scanf("%d", &banyakPartisi);

    float panjangPartisi = fDivide(fMin(batas1, batas0), banyakPartisi);

    float x;
    for (int i = 0; i < banyakPartisi; i ++){
        x = fPlus(batas0, fTimes(panjangPartisi, i));
        for (int j = 0; j < banyakKoef; j++){
            hasil = fPlus(hasil, fTimes(koef[j], fPower(x, j)));
        }
    }

    hasil = fTimes(hasil, panjangPartisi);

    printf("%.3f", hasil);

    /* Integral menggunakan Riemann kiri */
    /* Dengan rumus f(x) = a1 * x^0 + a2 * x^1 + a3 * x^2... */

    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
    return 0;
}
