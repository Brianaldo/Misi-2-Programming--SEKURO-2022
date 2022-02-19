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
    /* Mengembalikan value a - b */
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
    float x = a;
    for (int i = 1; i < b; i++){
        a = x * a ;
    }
    return a;
}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    float x = *a;
    for (int i = 1; i < b; i++){
        *a = x * *a;
    }
    
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */

    printf("-----------------------KALKULATOR INTEGRAL REIMANN (KIRI)-----------------------\n");

    int derajat;
    printf("Masukkan derajat polinom: ");
    scanf("%d", &derajat);

    int Llist = fPlus(derajat, 1);
    float fungsi[Llist];
    for (int i = 0; i < Llist ; i++){
        printf("Masukkan koefisien x derajat ke %d : ",(i));
        scanf("%f", &fungsi[i]);
    }


    float a; // batas bawah
    float b; // batas atas
    int N; // partisi
    printf("masukkan batas bawah: ");
    scanf("%f", &a);
    printf("masukkan batas atas: ");
    scanf("%f", &b);
    printf("masukkan banyak partisi: ");
    scanf("%d", &N);

    float hasil = 0, x = 0;
    float dx = fDivide(fMin(b, a), N); //∆x

    //perhitungan reiman kiri
   for (int i = 0; i < N; i++) {

            x = fPlus(a, fTimes(fMin(b, a), fDivide(i, N)));  //x ke i

            for (int j = 0; j < Llist; j++) {

            pPlus(&hasil, fTimes(fungsi[j], fPower(x, j))); // fx ke j lalu ditambahkan ke hasil 
           
            }

        }
   
    pTimes(&hasil,dx); //hasil dikalikan dengan interval (∆x)
    printf("%f",hasil);

    return 0;
}
