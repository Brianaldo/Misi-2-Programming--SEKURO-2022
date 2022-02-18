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

float fPower(float a, int b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    float product = 1;
    /* Mengembalikan value a ^ b */
    for (int i = 0; i < b; i++) {
        product *= a;
    }
    return product;
}

void pPower(float *a, int b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    float product = 1;
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    for (int i = 0; i < b; i++) {
        product *= *a;
    }
    /* F.S. a menjadi a ^ b */
    *a = product;
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
    
    // Input derajat polinom
    int derajat;
    printf("Masukkan derajat polinom f(x): ");
    scanf("%d", &derajat);
    printf("\n");
    
    // Input koefisien dan konstanta polinom
    printf("Masukkan koefisien dari tiap derajat pada polinom f(x) = a1 + a2 * x + a3 * x^2 + ... an * x^n\n(Format input: a1 a2 a3 ... an)\nInput: ");
    
    int sizeArrKoef = fPlus(derajat, 1);
    float koef[sizeArrKoef];
    for (int i = 0; i < sizeArrKoef; i++) {
        scanf("%f", &koef[i]);
    }
    printf("\n");
    
    // Display f(x) yang telah diinput
    printf("f(x) = ");
    for (int i = 0; i < sizeArrKoef; i++) {
        if (i == 0) {
            printf("%.3f + ", koef[i]);
        } else if (i > 0 && i < derajat) {
            printf("%.3fx^%d + ", koef[i], i);
        } else {
            printf("%.3fx^%d\n", koef[i], i);
        }
    }
    printf("\n");

    // Input batas atas dan batas bawah integral
    float batasAtas, batasBawah;
    printf("Masukkan batas atas dan batas bawah integral(Format input: batasAtas batasBawah): ");
    scanf("%f %f", &batasAtas, &batasBawah);

    // Input jumlah segiempat yang akan dibentuk
    int pecah;
    printf("Masukkan jumlah segiempat yang akan dibentuk: ");
    scanf("%d", &pecah);
    printf("\n");
    
    // Input pemilihan metode riemann yang akan digunakan
    int jenisRiemann = 0;
    printf("Pilih metode riemann yang akan digunakan: \n(1) Jumlah Riemann Tengah\n(2) Jumlah Riemann Kiri\n(3) Jumlah Riemann Kanan\n");
    while (jenisRiemann < 1 || jenisRiemann > 3) {
        printf("Metode: ");
        scanf("%d", &jenisRiemann);
        if (jenisRiemann < 1 || jenisRiemann > 3) {
            printf("Input anda salah (harus antara 1, 2, atau 3).\n");
        }
    }

    // Proses perhitungan integral riemann
    float sum = 0, x = 0;
    for (int i = 0; i < pecah; i++) {
        
        if (jenisRiemann == 1) {
            x = fDivide(fPlus(fPlus(batasBawah, fTimes(fMin(batasAtas, batasBawah), fDivide(i, pecah))), fPlus(batasBawah, fTimes(fMin(batasAtas, batasBawah), fDivide(fPlus(i, 1), pecah)))), 2);
        }
        else if (jenisRiemann == 2) {
            x = fPlus(batasBawah, fTimes(fMin(batasAtas, batasBawah), fDivide(i, pecah)));
        }
        else if (jenisRiemann == 3) {
            x = fPlus(batasBawah, fTimes(fMin(batasAtas, batasBawah), fDivide(fPlus(i, 1), pecah)));
        }

        for (int j = 0; j < sizeArrKoef; j++) {
            
            pPlus(&sum, fTimes(koef[j], fPower(x, j)));

        }
    }
    pTimes(&sum, fDivide(fMin(batasAtas, batasBawah), pecah));

    // Display hasil integral riemann
    printf("Hasil = %.4f", sum);
    return 0;
}