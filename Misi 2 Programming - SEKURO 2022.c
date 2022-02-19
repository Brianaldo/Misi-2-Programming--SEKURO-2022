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
    /* F.S. a menjadi a * b */
    *a /= b;
}

float fPower(float a, float b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
    int i;
    int pangkat = 1;
    for (i = 0; i < b; i++){
        pangkat = pangkat * a;
    } return pangkat;
}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    int i;
    int pangkat = 1;
    for (i = 0; i < b; i++){
        pangkat = *a * pangkat;
    } 
    *a = pangkat;
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
    
    /* Main Program */
	//Input
	int a,b,n;
	int koefisien, pangkat,partisi;
	// Pendefinisian batas limit
	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);
	// Pendefinisian fungsi
	printf("Given a function f(x) = Ax^B\n");
	printf("Enter A: ");
	scanf("%d", &koefisien);
	printf("Enter B: ");
	scanf("%d", &pangkat);
	// pendefinisian jumlah partisi
	printf("Enter n (Partition): ");
	scanf("%d", &partisi);
	
	//Process
	float deltaX = fDivide(fMin(b,a),partisi);
	float jlh = 0;
	float y;
	if (pangkat != 0){
		for (float i = a; i <= b; i+=deltaX){
			if (i == 0) {
				y = fTimes(koefisien,0);
			}
			else {
				y = fTimes(koefisien,fPower(i,pangkat));
			}
			jlh = fPlus(jlh,fTimes(deltaX,y));
			printf("%f %f\n",i,deltaX);
			printf("%f\n",y);
			printf("%f\n",jlh);
		}
	}
	else {
		for (float i = a; i <= b; i+=deltaX){
			if (i == 0) {
				y = fTimes(koefisien,0);
			}
			else {
				y = fTimes(koefisien,1);
			}
			jlh = fPlus(jlh,fTimes(deltaX,y));
		}
}

