#include <stdio.h>
#include <stdbool.h>

float ans, jwb, ret, k[10000000+5], in, fi;
int x;

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
    /* F.S. a menjadi a / b */
    *a /= b;
}

float fPower(float a, float b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */
    ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans *= a;
    }
    return ans;
}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */
    for (int i = 1; i < b; i++)
    {
        *a *= *a;
    }
}

float func(float d)
{
	ret = 0;
	for (int i = 0; i <= x; i++)
	{
		pPlus(&ret, fTimes(k[i],fPower(d,i)));
	}
	return ret;
}

float itg(float a, float b)
{
	jwb = 0;
	for (float i = a; i - 0.001 <= b; i += 0.001)
	{
		pPlus(&jwb, fDivide(fTimes(fPlus(func(i), func(fPlus(i, 0.001))), 0.001), 2));
	}
	return jwb;
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */
    printf("Masukkan derajat terbesar: ");
	scanf("%d", &x);
	for (int i = x; i >= 0; i--)
	{
		printf("Masukkan koefisien pada derajat %d: ", i);
		scanf("%f", &k[i]);
	}
	printf("f(x) = ");
	for (int j = x; j > 1; j--)
	{
		if (j == x)
		{
			printf("%fx^%d ", k[j], j);
		}
		else
		{
			if (k[j] > 0)
			{
				printf("+%fx^%d ", k[j], j);
			}
			else
			{
				if (k[j] < 0)
				{
					printf("%fx^%d ", k[j], j);
				}
			}
		}
	}
	if (k[1] != 0)
	{
		if (k[1] > 0)
		{
			printf("+%fx ", k[1]);
		}
		else
		{
			printf("%fx ", k[1]);
		}
	}
	if (k[0] != 0)
	{
		if (k[0] > 0)
		{
			printf("+%f", k[0]);
		}
		else
		{
			printf("%f", k[0]);
		}
	}
	printf("\n");
	printf("Masukkan batas atas: ");
	scanf("%f", &fi);
	printf("Masukkan batas bawah: ");
	scanf("%f", &in);
	printf("Hasil integral Riemann: %f", itg(in, fi));
    return 0;
}
