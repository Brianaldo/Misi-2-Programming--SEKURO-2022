#include <stdio.h>
#include <stdbool.h>

float fPlus(float a, float b) {
    return a + b;
}

void pPlus(float a, float b) {
    a+= b;
}

float fMin(float a, float b) {
    return a - b;
}

void pMin(float a, float b) {
    a -=b;
}

float fTimes(float a, float b) {
    return a*b;
}

void pTimes(float a, float b) {
    a = a*b;
}

float fDivide(float a, float b) {
    return a/b;
}

void pDivide(float a, float b) {
    a = a/b;
}

float fPower(float a, float b) {
    for (int i=1;i<b;i++){
    	a= a*a;
	}
	return a;
}

void pPower(float a, float b) {
    for (int i=1;i<b;i++){
    	a= a*a;
	}
}

float Riemann1 (float awal, float akhir, float inc){
	// fungsi f(x) = 2x^2 +3x-5
	// konsep perhitungan menggunakan konsep Riemann kiri
	float hasil = 0;
	float y;
	for (awal; awal< akhir; awal += inc ){
		if (akhir-awal < inc){ //Hanya berlaku untuk perhitungan paling terakhir
			inc = fMin(akhir,awal);
		}
		y = fMin(fPlus(fTimes(2,fPower(awal,2)),fTimes(3,awal)),5);
		hasil = fPlus(fTimes(y,inc),hasil);
	//	printf("%f, %f \n",awal,y);
	}	
	return hasil;
}

float Riemann2 (float awal, float akhir, float inc){
	// fungsi f(x) = 3x^2 -4x +7
	// konsep perhitungan menggunakan konsep Riemann kiri
	float hasil = 0;
	float y;
	for (awal; awal< akhir; awal += inc ){
		if (akhir-awal < inc){ //Hanya berlaku untuk perhitungan paling terakhir
			inc = fMin(akhir,awal);
		}
		y = fPlus(fMin(fTimes(3,fPower(awal,2)),fTimes(4,awal)),7);
		hasil = fPlus(fTimes(y,inc),hasil);
	//	printf("%f, %f \n",awal,y);
	}	
	return hasil;
}

float Riemann3 (float awal, float akhir, float inc){
	// fungsi f(x) = 5x^2+4x-9
	// konsep perhitungan menggunakan konsep Riemann kiri
	float hasil = 0;
	float y;
	for (awal; awal< akhir; awal += inc ){
		if (akhir-awal < inc){ //Hanya berlaku untuk perhitungan paling terakhir
			inc = fMin(akhir,awal);
		}
		//	y = fTimes(2,fPower(awal,2))+ fTimes(3, awal) - 5
		y = fMin(fPlus(fTimes(5,fPower(awal,2)),fTimes(4,awal)),9);
		hasil = fPlus(fTimes(y,inc),hasil);
	//	printf("%f, %f \n",awal,y);
	}	
	return hasil;
}

float awal;
float akhir;
float deltax;
int pilihan;
float hasilAkhir;

int main() {
	printf("Masukkan batas awal \n");
	scanf("%f", &awal);
	printf("Masukkan batas akhir \n");
	scanf("%f", &akhir);
	printf("Masukkan batas deltax \n");
	scanf("%f", &deltax);
	
	printf("Pilihan 1 -> Fungsi f(x) = 2x^2+3x-5  \n");
	printf("Pilihan 2 -> Fungsi f(x) = 3x^2-4x+7  \n");
	printf("Pilihan 3 -> Fungsi f(x) = 5x^2+4x-9  \n");
	scanf("%d", &pilihan);
	
	if (pilihan == 1){
		hasilAkhir= Riemann1(awal, akhir, deltax);
		printf("%f", hasilAkhir);
	}
	else if (pilihan== 2){
		hasilAkhir = Riemann2(awal, akhir,deltax);
		printf("%f", hasilAkhir);
	}
	else if (pilihan == 3){
		hasilAkhir = Riemann3 (awal, akhir, deltax);
		printf("%f", hasilAkhir);
	}
	else {
		printf("Tidak pada pilihan.");
	}
	
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
    return 0;
}
