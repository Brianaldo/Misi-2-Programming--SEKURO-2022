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

float fPower(float a, int b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
    if (b == 0){
        return 1;
    }
    else if (b>0){
        return (fTimes(a,fPower(a,b-1)));
    }
    else{
        return (fDivide(fPower(a,b+1),a));
    }
}

void pPower(float *a, int b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    float temp = *a;
    if (b==0){
        pTimes(a,0);pPlus(a,1);
    }
    else if (b>0){
        for(int i=0;i<b-1;i++){
            pTimes(a,temp);
        }
    }
    else{
        for(int i=0;i>=b;i--){
            pDivide(a,temp);
        }
    }
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
    printf("Program akan menghitung integral numerik dengan jumlah riemann kiri atau kanan");
    printf("Apakah riemann kiri (l) atau riemann kanan (r) yang akan digunakan? (l/r)\n");
    char riemann;
    scanf("%c",&riemann);
    printf("Input hanya dapat berupa polinomial, tidak dengan trigonometri\n");
    float res, atas, bawah, jarak; int partisi, coeff, pangkat;
    res = 0;
    printf("Masukkan batas bawah: ");
    scanf("%f", &bawah);
    printf("Masukkan batas atas: ");
    scanf("%f", &atas);
    printf("Masukkan nilai n: ");
    scanf("%d", &partisi);
    jarak = fDivide(fMin(atas,bawah),partisi);
    printf("Untuk mengakhiri input, masukkan koefisien dengan -9999\n");
    while(true){
        printf("Masukkan koefisien: ");
        scanf("%d", &coeff);
        if(coeff==-9999)break;
        printf("Masukkan pangkat: ");
        scanf("%d", &pangkat);
        //printf("%d %d", coeff, pangkat);
        if(riemann == 'l'){
            for(float i=bawah;i<atas;pPlus(&i,jarak)){
                pPlus(&res,fTimes(coeff,fPower(i,pangkat)));
            }
        }
        else{
            pPlus(&bawah,jarak);
            for(float i=bawah;i<=atas;pPlus(&i,jarak)){
                pPlus(&res,fTimes(coeff,fPower(i,pangkat)));
            }
            pMin(&bawah,jarak);
        }
    }
    pTimes(&res,fDivide(fMin(atas,bawah),partisi));
    printf("Hasilnya adalah: %f\n",res);
    return 0;
}