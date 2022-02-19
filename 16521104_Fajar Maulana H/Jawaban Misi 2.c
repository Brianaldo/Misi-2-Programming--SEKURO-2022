#include <stdio.h>

#include <stdbool.h>

float fPlus(float a, float b) {
  return a + b;
  /* Function tambah */
  /* Mengembalikan value a + b */
}

void pPlus(float * a, float b) {
  /* Procedure tambah */
  /* I.S. a dan b terdefinisi dan tidak sembarang */
  * a += b;
  /* F.S. a menjadi a + b */
}

float fMin(float a, float b) {
  /* Function kurang */
  return a - b;
  /* Mengembalikan value a + b */
}

void pMin(float * a, float b) {
  /* Procedure kurang */
  * a -= b;
  /* I.S. a dan b terdefinisi dan tidak sembarang */
  /* F.S. a menjadi a - b */
}

float fTimes(float a, float b) {
  /* Function kali */
  return a * b;
  /* Mengembalikan value a * b */
}

void pTimes(float * a, float b) {
  /* Procedure kali */
  /* I.S. a dan b terdefinisi dan tidak sembarang */
  * a *= b;
  /* F.S. a menjadi a * b */
}

float fDivide(float a, float b) {
  /* Function bagi */
  return a / b;
  /* Mengembalikan value a / b */
}

void pDivide(float * a, float b) {
  /* Procedure bagi */
  /* I.S. a dan b terdefinisi dan tidak sembarang */
  * a /= b;
  /* F.S. a menjadi a * b */
}

float fPower(float a, float b) {
  /* Function pangkat */
  /* Asumsi b adalah int */
  float result = 1;
  for (int i = 0; i < b; i++) {
    result = result * a;
  }
  return result;
  /* Mengembalikan value a ^ b */
}

void pPower(float * a, float b) {
  int num = 1;
  for (int i = 0; i < b; i++) {
    num *= * a;
  }
  /* Procedure pangkat */
  /* Asumsi b adalah int */
  /* I.S. a dan b terdefinisi dan tidak sembarang */
  /* F.S. a menjadi a ^ b */
}

int main() {

  /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
  /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan
            prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
  /* Input dan output dibebaskan kepada Cakru URO 14 */
  /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
  int atas, bawah, n;
  printf("Masukkan nilai batas atas: ");
  scanf("%d", & atas);
  printf("Masukkan nilai batas bawah: ");
  scanf("%d", & bawah);
  printf("Masukkan n: ");
  scanf("%d", & n);
  int derajat, koefisien;
  printf("masukkan derajat: ");
  scanf("%d", & derajat);
  int koef[derajat + 1];
  for (int i = 0; i <= derajat; i++) {
    printf("Masukkan koefisien pangkat ke-%d: ", i);
    scanf("%d", & koef[i]);
  }
  float dx;
  dx = fDivide(fMin(atas, bawah), n);
  float result;
  for (int i = 0; i < n; i++) {
    float fungsi = 0;
    for (int a = 0; a <= derajat; a++) {
      fungsi = fPlus(fungsi, fTimes(koef[a], fPower((fPlus(bawah, fTimes(i, dx))), a)));
    }
    result = fPlus(result, fTimes(fungsi, dx));
  }
  printf("Hasil Integral: %f\n", result);
  return 0;
}