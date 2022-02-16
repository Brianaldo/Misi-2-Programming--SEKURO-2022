#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b)
{
    /* Function tambah */
    /* Mengembalikan value a + b */
    return a + b;
}

void pPlus(float *a, float b)
{
    /* Procedure tambah */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a + b */
    *a += b;
}

float fMin(float a, float b)
{
    /* Function kurang */
    /* Mengembalikan value a + b */
    return a - b;
}

void pMin(float *a, float b)
{
    /* Procedure kurang */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a - b */
    *a -= b;
}

float fTimes(float a, float b)
{
    /* Function kali */
    /* Mengembalikan value a * b */
    return a * b;
}

void pTimes(float *a, float b)
{
    /* Procedure kali */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a * b */
    *a *= b;
}

float fDivide(float a, float b)
{
    /* Function bagi */
    /* Mengembalikan value a / b */
    return a / b;
}


// Buat Fungsi/Prosedur Tambahan Supaya mainnya rapih
// Semua operasi aritmatika tetap menggunakan fungsi yang di atas
void displayFunction(int *koef, int derajat)
{
    // Prosedur untuk menampilkan fungsi 
    printf("Fungsi yang akan diintegral adalah:\n");
    for (int i = derajat; i >= 1; i--){
        if (i != 1){
            if (koef[i] != 0){
                if (koef[i] != 1 && koef[i] != -1){
                    printf("%dx^%d + ", koef[i], i);
                } else {
                    if (koef[i] == 1){
                        printf("x^%d + ", i);
                    } else {
                        printf("-x^%d + ", i);
                    }   
                }
            }
        } else {
            if (koef[i] != 0){
                if (koef[i] != 1 && koef[i] != -1){
                    printf("%dx^%d + ", koef[i], i);
                } else {
                    if (koef[i] == 1){
                        printf("x + ");
                    } else {
                        printf("-x + ");
                    }   
                }
            }
        }
        
    }
    if (koef[0] != 0){
        printf("%d", koef[0]);
    } else {
        printf("0");
    }
    printf("\n");
}

float getVal(int *koef, int derajat, float a){
    // Fungsi untuk mengembalikan nilai saat fungsi dimasukkan nilai a
    float result = 0;
    float s = a;
    pPlus(&result, koef[0]);
    for (int i = 1; i <= derajat; i++){
        for (int j = 0; j < i-1; j++){
            pTimes(&s, a); // bruteforce
        }
        pPlus(&result, fTimes(koef[i], s));
        s = a;
    }
    return result;
}

float integrateRiemann(int *koef, int derajat, float a, float b, float n){
    // Fungsi utama dari program ini, yaitu menghitung integral dengan konsep Integral Riemann
    float riemannSum = 0; // Menyimpan hasil integral
    float val = fDivide(fMin(b, a), n);
    for (int i = 1; i <= n; i++){ // Loop sebanyak n partisi; 
        float temp = 0; // Inisialisasi temp dengan nol
        temp = fTimes(val, i); 
        pPlus(&temp, a); // temp bernilai temp + a (ekivalen dengan nilai pada sumbu x)
        temp = getVal(koef, derajat, temp); // temp diupdate nilainya menjadi f(temp)
        pTimes(&temp, val); // f(temp) dikalikan dengan lebar partisi
        pPlus(&riemannSum, temp); 
    } 
    return riemannSum;
}

int main()
{
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
     
    char ui; // user input
    do {
    // Deklarasi variabel
    int derajat; // Polynomial degree
    float n = 100000; // partition
    float a; // lower bound
    float b; // upper bound
    
    // User input Function
    printf("Masukkan derajat terbesar: ");
    scanf("%d", &derajat);

    int koef[derajat+1]; // Integral Riemann akan diterapkan menggunakan array karena derajat sudah dipastikan >= 0 
                         // sehingga index array dapat dieksploitasi

    for (int i = derajat; i >= 0; i--){ // Pengisian dimulai dari koefisien derajat tertinggi
        int c;
        printf("Masukkan koefisien derajat ke-%d: ", i); 
        scanf("%d", &c);
        koef[i] = c;
    }

    // Display Function
    displayFunction(koef, derajat);

    // Get lower and upper bound
    printf("Masukkan batas bawah: ");
    scanf("%f", &a);
    printf("Masukkan batas atas: ");
    scanf("%f", &b);

    // Print result
    printf("Hasil Integral adalah: %.2f\n", integrateRiemann(koef, derajat, a, b, n));

    
    printf("Apakah anda ingin menghitung integral riemann lagi?[y/n]: ");
    scanf(" %c", &ui);
    while (ui != 'n' && ui != 'y'){
        printf("Invalid Input!\n");
        printf("Apakah anda ingin menghitung integral riemann lagi?[y/n]: ");
        scanf(" %c", &ui);
    }
    } while (ui == 'y');

    return 0;
}
