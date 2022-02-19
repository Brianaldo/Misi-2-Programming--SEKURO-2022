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
    return a/b;
}

void pDivide(float *a, float b) {
    /* Procedure bagi */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
    *a *= b;
}

float fPower(float a, float b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
    int power = 1;
    float temp_a = a;

    while(power!=b){
        temp_a *= a;
        power += 1;
    }

    return temp_a;
}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    *a = fPower(*a, b);
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */

    printf("Kalkulator integral fungsi polinom sederhana menggunakan metode Riemann\n");
    printf("Oleh: Muhammad Afief Abdurrahman - 16021257\n\n");
    int batasBawah, batasAtas, derajat;

    printf("Masukkan derajat polinom integral: ");
    scanf("%d", &derajat);
    int banyakElemen = fPlus(derajat, 1);
    float koefisien[banyakElemen];

    float sum = 0;

    int partisi = 10000;

    printf("Masukkan batas atas integral: ");
    scanf("%d", &batasAtas);

    printf("Masukkan batas bawah integral: ");
    scanf("%d", &batasBawah);

    for(int i=0; i<=derajat; ++i){
        float temp_coef;
        printf("Masukkan koefisien dari x^%d: ", i);
        scanf("%f", &temp_coef);

        koefisien[i] = temp_coef;
    }

    float deltaX = fDivide(fMin(batasAtas, batasBawah), partisi);

    for(int j=0; j<=partisi; ++j){
        // float x_i = batasBawah + deltaX*j;
        float x_i = fPlus(batasBawah, fTimes(deltaX, j));
        float sum_of_f = 0;

        // hitung f(x_i)
        for(int k=0; k<=derajat; ++k){
            float temp_sum = 0;
            if(k==0){
                // temp_sum += koefisien[k];
                pPlus(&temp_sum, koefisien[k]);
            } else{
                // temp_sum += koefisien[k]*(fPower(x_i, k))
                pPlus(&temp_sum, fTimes(koefisien[k], fPower(x_i, k)));
            }
            // sum_of_f += temp_sum;
            pPlus(&sum_of_f, temp_sum);
        }
        pPlus(&sum, fTimes(sum_of_f, deltaX));
    }

    printf("Hasil dari integral adalah %.3f", sum);
    return 0;
}
