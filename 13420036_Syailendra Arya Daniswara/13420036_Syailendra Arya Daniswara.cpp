#include <stdio.h>
#include <stdbool.h>
using namespace std;
float a;
float b;
float c;
float d;
float e;
float f;
float pangkat = 1 ;
int n;
float hasil = 0;
char Persamaan;
float fPlus(float a, float b) {
    return c  ;
}

void pPlus(float *a, float b) {
    c = *a + b ;
}

float fMin(float a, float b) {
	return d ;
}

void pMin(float *a, float b) {
    d = *a - b ;
}

float fTimes(float a, float b) {
    return e ;
}

void pTimes(float *a, float b) {
    e = *a * b ;
}

float fDivide(float a, float b) {
    return f ; 
}

void pDivide(float *a, float b) {
     f = *a / b ;
}


float fPower(float a, float b) {
   	return pangkat ; 
}

void pPower(float *a, float b) {
	for (int i = 1; i <= b; i++)
		pangkat=pangkat**a;
	
} 

int main() 

{
	printf("Masukkan Nilai n :");
	scanf("%f",&n);
	printf("Masukkan Nilai a :");
	scanf("%f",&a);
	printf("Masukkan Nilai b :");
	scanf("%f",&b);
	// Asumsi = X^2- 4x + 5 //
	
	float k;
	float h = (b-a)/n;
	
	for (int i = 0 ; i <= h; i++ ) {
		k = a + (i*n);
		pTimes(&k, 4);
		pPower(&k, 2);
		pMin(&pangkat, e);
		pPlus(&d, 5);
		pTimes(&c, h);
		hasil += e;
	}
		
	printf("%f /n", hasil);
	
    return 0;
}
