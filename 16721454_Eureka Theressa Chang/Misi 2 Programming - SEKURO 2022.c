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
    return a + b;
}

void pMin(float *a, float b) {
    /* Procedure kurang */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a - b */
    *a -= b;
}

void pMinint(int *a, int b) {
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

float fPower(float a, float b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
    long long int value=1;
    while (b!=0)
    {
        value *= a;  
      --b;
    };
    return value;
}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    float c = *a;
    while (b!=1)
    {
        *a *= c;
        --b;  
    };
}

int main() {
    //input pengguna dianggap selalu benar sehingga tidak ada salah penginputan
    float x1, x2, z; 
    int a1, b1;
    char yn1 ; 
    printf("Selamat datang ke kalkulator integral! \n");
    printf("Untuk memulai, harap mendeskripsikan fungsi terlebih dahulu. \n");
    printf("1. Apakah fungsi anda memiliki penyebut selain 1? (y/n)\n");
    scanf("%c", &yn1);

    //Jika fungsi memiliki penyebut
    if (yn1 == 'y') { 
        //Mengisi fungsi pembilang
        printf("Pengisian pembilang: \n");
        printf("Misalkan 'Kx^n' = a, dengan K=konstanta,\n");
        printf("dan n=pangkat x, berapa banyak a dalam pembilang anda? ");
        scanf("%d", &a1);
        
        int pkt1[a1-1], kons1[a1-1];
        int k1;
        int i = 1;

        printf("\n");
        printf("(Isi dari pangkat terbesar) \n");

        while (i != a1+1) {
            printf("Masukkan Konstanta x ke-%d: ", i);
            scanf("%d", &kons1[i-1]);
            printf("Masukkan Pangkat x ke-%d: ", i);
            scanf("%d", &pkt1[i-1]);
            printf("\n");
            i+= 1;
        };

        printf("Masukkan nilai konstanta pada pembilang: ");
        scanf("%d", &k1);
        printf("\n");

        //Mengisi fungsi penyebut
        printf("Pengisian penyebut: \n");
        printf("Misalkan 'Kx^n' = b, dengan K=konstanta,\n");
        printf("dan n=pangkat x, berapa banyak b dalam pembilang anda? ");
        scanf("%d", &b1);
        
        int pkt2[b1-1], kons2[b1-1];
        int k2;
        int j = 1;

        printf("\n");
        printf("(Isi dari pangkat terbesar) \n");

        while (j != b1+1) {
            printf("Masukkan Konstanta x ke-%d: ", j);
            scanf("%d", &kons2[j-1]);
            printf("Masukkan Pangkat x ke-%d: ", j);
            scanf("%d", &pkt2[j-1]);
            printf("\n");
            j += 1;
        };

        printf("Masukkan nilai konstanta pada penyebut: ");
        scanf("%d", &k2);
        printf("\n");

        //Menuliskan ulang fungsi f(x)
        printf("Berikut fungsi anda: \n");
        int h1 = 0;
        for (h1 == 0; h1 != a1; ++h1) {
            printf("%d", kons1[h1]);
            printf("x^");
            printf("%d", pkt1[h1]);
            printf(" + ");
        }
        printf("%d \n", k1);
        printf("------------------ \n");
        int h2 = 0;
        for (h2 == 0; h2 != b1; ++h2) {
            printf("%d", kons2[h2]);
            printf("x^");
            printf("%d", pkt2[h2]);
            printf(" + ");
        }
        printf("%d \n", k2);

       //Bagian pengintegralan

        float ppx = 0 ;
        float jmlx1 = 0;
        float jmlx2 = 0;
        float fnltally= 0;
        float ffxpem, ffxpey; 
        int add = 0; 
        int add2 = 0;
        float endres = 0;
        
        printf("Masukkan partisi untuk integral (dx): \n");
        scanf("%f", &z);
        printf("Masukkan batas bawah integral: \n");
        scanf("%f", &x1);
        printf("Masukkan batas atas integral: \n");
        scanf("%f", &x2);
        
        while (x1 != x2+1) {
            while (add != a1) {    
                pPlus(&ppx, x1);
                pPower(&ppx, pkt1[add]);
                pTimes(&ppx, kons1[add]);
                pPlus(&jmlx1, ppx);
                pMin(&ppx, ppx);
                ++add;
            };
            while (add2 != b1) {
                ppx = x1;
                pPower(&ppx, pkt2[add2]);
                pTimes(&ppx, kons2[add2]);
                pPlus(&jmlx2, ppx);
                pMin(&ppx, ppx);
                ++add2;
            };
            
            pPlus(&ffxpem, jmlx1);
            pPlus(&ffxpem, k1);
            pPlus(&ffxpey, jmlx2);
            pPlus(&ffxpey, k2);

            //jumlah integral
            endres = fDivide(ffxpem, ffxpey);
            pTimes(&endres, z);
            pPlus(&fnltally, endres);

            //reset storage data
            pMin(&ffxpem, ffxpem);
            pMin(&ffxpey, ffxpey);
            pMin(&endres, endres);
            pMinint(&add, add);
            pMinint(&add2, add2);
            pMin(&jmlx1, jmlx1);
            pMin(&jmlx2, jmlx2);

            pPlus(&x1, z);
        }; 

        printf("Hasil integralnya adalah: %f \n", fnltally);
    //Jika fungsi tidak memiliki penyebut
    } else { 
        //Mengisi fungsi 
        printf("Pengisian fungsi: \n");
        printf("Misalkan 'Kx^n' = a, dengan K=konstanta,\n");
        printf("dan n=pangkat x, berapa banyak a dalam pembilang anda? ");
        scanf("%d", &a1);
        
        int pkt1[a1-1], kons1[a1-1];
        int k1;
        int i = 1;

        printf("\n");
        printf("(Isi dari pangkat terbesar) \n");

        while (i != a1+1) {
            printf("Masukkan Konstanta x ke-%d: ", i);
            scanf("%d", &kons1[i-1]);
            printf("Masukkan Pangkat x ke-%d: ", i);
            scanf("%d", &pkt1[i-1]);
            printf("\n");
            i+= 1;
        };

        printf("Masukkan nilai konstanta: ");
        scanf("%d", &k1);
        printf("\n");

        //Menuliskan ulang fungsi f(x)
        printf("Berikut fungsi anda: \n");
        int h1 = 0;
        for (h1 == 0; h1 != a1; ++h1) {
            printf("%d", kons1[h1]);
            printf("x^");
            printf("%d", pkt1[h1]);
            printf(" + ");
        }
        printf("%d \n", k1);

        //Bagian pengintegralan

        float ppx = 0 ;
        float jmlx1 = 0;
        float fnltally= 0;
        float ffxpem; 
        int add = 0; 
        
        printf("Masukkan partisi untuk integral (dx): \n");
        scanf("%f", &z);
        printf("Masukkan batas bawah integral: \n");
        scanf("%f", &x1);
        printf("Masukkan batas atas integral: \n");
        scanf("%f", &x2);
        
        while (x1 != x2+1) {
            while (add != a1) {    
                pPlus(&ppx, x1);
                pPower(&ppx, pkt1[add]);
                pTimes(&ppx, kons1[add]);
                pPlus(&jmlx1, ppx);
                pMin(&ppx, ppx);
                ++add;
            };
            
            pPlus(&ffxpem, jmlx1);
            pPlus(&ffxpem, k1);
            
            //jumlah integral
            pTimes(&ffxpem, z);
            pPlus(&fnltally, ffxpem);

            //reset storage data
            pMin(&ffxpem, ffxpem);
            pMinint(&add, add);
            pMin(&jmlx1, jmlx1);

            pPlus(&x1, z);
        }; 

        printf("Hasil integralnya adalah: %f \n", fnltally);
    };

    return 0;
}

/*
variables list
z = delta x / partisi integral (%f)
x1 = batas bawah (%d)
x2 = batas atas (%d)
a, b, c, value  = pemisalan (%f) 
a1 =  banyak Kx^n di pembilang (%d)
b1 =  banyak Kx^n di penyebut (%d)
yn1 = jawaban user (%c)
pkt1 = array pangkat pembilang
pkt2 = array pangkat penyebut
kons1 = array konstanta x pada pembilang
kons2 = array konstanta x pada penyebut
k1 = nilai konstanta pada pembilang (%d)
k2 = nilai konstanta pada penyebut (%d)
ppx = array x yang sudah dipangkatkan
jmlx1 = array jumlah pembilang
jmlx2 = array jumlah penyebut 
fnltally = hasil integral
ffxpem = hasil jumlah x di pembilang
ffxpem = hasil jumlah x di penyebut
endres = hasil integral di interval (x, x+z)
*/