#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    /* Function tambah */
    /* Mengembalikan value a + b */
    return (a+b);
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
    return (a-b);
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
    return (a*b);
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
    return(a/b);
}

void pDivide(float *a, float b) {
    /* Procedure bagi */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
    *a /= b;
}

float fPower(float a, int b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
    float res = 1;
    if (b==0){
        for (int i=0;i<b;i++){
            res=fTimes(res,a);
        }
    }
    else if (b>0){
        for (int i=0;i<b;i++){
            res=fTimes(res,a);
        }
    }
    else{
        for (int i=0;i>b;i--){
            res=fDivide(res,a);
        }
    }
    return res;
}

void pPower(float *a, int b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    float res = *a;
    if(b==0){
        *a *= 0, *a += 1;
    }
    else if(b>0){
        for(int i=0;i<b-1;i++){
            *a *= res;
        }
    }
    else{
        for(int i=0;i>b;i--){
            *a /= res;
        }
    }
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */

    // Terdapat asumsi bahwa pangkat suatu suku selalu bilangan bulat

    //Input
    // printf("Program akan menghitung integral dengan konsep Integral Riemann Kanan\n");
    // printf("Masukkan fungsi dengan bentuk [koefisien]X[pangkat] tanpa spasi\n");
    // printf("Akhiri fungsi dengan tanda '.'"); //Memudahkan untuk mencari akhir dari fungsi
    // printf("Sebagai contoh: 1x2+3x+2.\n");
    // printf("Masukkan fungsi: ");
    // char fx[50];
    // scanf("%49s", &fx);
    // float bb,ba;
    // printf("Masukkan batas bawah integral: ")
    // scanf("%f", &bb);
    // printf("Masukkan batas atas integral: ")
    // scanf("%f", &ba);
    
    // Test Fungsi Pangkat
    // float a,b;
    // scanf("%f %f", &a, &b);
    // pPower(&a,b);
    // printf("%f", a);

    return 0;
}
