#include <stdio.h>
#include <stdbool.h>

// untuk error checking, 
// sebenarnya tidak digunakan untuk kasus ini, karena tidak menggunakan operasi pembagian
// namun tetap dibuat karena ada division by zero error pada salah satu fungsi
struct ErrCode {
    int code;
} errCode;

float fPlus(float a, float b) {
    /* Function tambah */
    /* Mengembalikan value a + b */
    return a + b;
}

void pPlus(float* a, float b) {
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

void pMin(float* a, float b) {
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

void pTimes(float* a, float b) {
    /* Procedure kali */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
    *a *= b;
}

float fDivide(float a, float b) {
    /* Function bagi */
    /* Mengembalikan value a / b */
    if (b == 0) {
        perror("Tidak dapat membagi dengan nol");
        errCode.code = -1;
        return 0.0;
    }
    return a / b;
}

void pDivide(float* a, float b) {
    /* Procedure bagi */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
    if (b == 0) {
        perror("Tidak dapat membagi dengan nol");
        errCode.code = -1;
        return;
    }
    *a /= b;
}

float fPower(float a, float b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
    int c = (int)b;
    if (b == 0) {
        return 1;
    }
    for (size_t i = 0; i < c - 1; ++i) {
        a *= a;
    }
    return a;
}

void pPower(float* a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    for (size_t i = 0; i < b - 1; ++i) {
        *a *= *a;
    }
}

void tukar(float* a, float* b) {
    pPlus(a, *b);
    *b = fMin(*a, *b);
    pMin(a, *b);
    /*
        a = *a + *b;
        b = *a - *b;
        a = *a - *b;
    */
}

/*
    Menghitung integral secara numerik (aproksimasi) untuk fungsi polinomial dengan derajat
    polinomial >= 0
*/


int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
              /* Input dan output dibebaskan kepada Cakru URO 14 */
              /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
    errCode.code = 0;
    int max_deg;
    int koef[1024];
    int additional_coeff = 1;
    printf("Masukkan derajat maksimum polinomial: ");
    scanf("%d", &max_deg);
    if (max_deg < 0) {
        perror("Derajat maksimum polinomial tidak boleh negatif");
        return 1;
    }
    if (max_deg >= 1024) {
        perror("Derajat maksimum polinomial tidak boleh melebihi 1023");
        return 1;
    }
    for (int i = max_deg; i >= 0; i = (int)fMin((float)i, 1)) {
        printf("Masukkan koefisien dari x^%d: ", i);
        scanf("%d", &koef[i]);
    }

    float delta = 0.001;
    float batas_kiri, batas_kanan;
    printf("Masukkan batas kiri integral: ");  scanf("%f", &batas_kiri);
    printf("Masukkan batas kanan integral: ");  scanf("%f", &batas_kanan);
    if (batas_kanan < batas_kiri) {
        // tukar batas artinya dikali -1
        tukar(&batas_kiri, &batas_kanan);
        additional_coeff = -1;
    }
    float total_sum = 0;
    for (float walk = batas_kiri; walk < batas_kanan; walk = fPlus(walk, delta)) {
        float ysum = 0;
        for (size_t i = 0; i <= (size_t)max_deg; i = (size_t)fPlus(i, 1)) {
            ysum = fPlus(ysum, koef[i] * fPower(walk, (float)i));
        }
        total_sum = fPlus(total_sum, ysum * delta);
    }
    total_sum = fTimes(total_sum, additional_coeff);
    printf("Hasil integral: %f\n", total_sum);

    return 0;
}
