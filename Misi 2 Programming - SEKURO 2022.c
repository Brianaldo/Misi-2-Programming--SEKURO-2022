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

void coef(float *array, int deg){
    // float array_of_coef[deg];
    for(int i=0; i<=deg; i++){
        float temp_coef;
        printf("Masukkan koefisien polinom dengan pangkat %d: ", i);
        scanf("%f", &temp_coef);
        // array_of_coef[i]=temp_coef;
        array[i]=temp_coef;
    }
}

float x_i(int i, int bawah, float delta_x){
    return fPlus(bawah, fTimes(i, delta_x));
    // return bawah + (i*delta_x);
}

float F_i(float xi, float *array_of_coef, int deg){
    float sum = 0;
    for(int j = 0; j<=(deg); j++){
        pPlus(&sum, fTimes(array_of_coef[j], fPower(xi, j)));
        // sum += array_of_coef[j]*(fPower(xi, j));
    }
    return sum;
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */

    int partition = 100;
    int deg;
    printf("Masukkan derajat polinom: ");
    scanf("%d", &deg);
    printf("Derajat polinom: %d\n", deg);
    float array_of_coef[deg];

    coef(array_of_coef, deg);

    int b, a;
    printf("Masukkan batas atas: ");
    scanf("%d", &b);
    printf("Masukkan batas bawah: ");
    scanf("%d", &a);
    float delta_x = fDivide(fMin(b, a), partition);
    // float delta_x = (b-a)/partition;
    printf("%.5f\n", delta_x);
    float sum = 0;
    for(int i=1; i<=partition; i++){
        printf("i: %d\n", i);
        float xi = x_i(i, a, delta_x);
        float Fi = F_i(xi, array_of_coef, deg);
        printf("Fi: %.1f\n", Fi);
        printf("xi: %.1f\n", xi);
        pPlus(&sum, fTimes(Fi, delta_x));
        // sum += Fi*delta_x;
        printf("sum: %.1f\n", sum);
    }
    return 0;
}
