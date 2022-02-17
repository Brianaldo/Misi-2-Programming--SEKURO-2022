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
    /* F.S. a menjadi a / b */

    *a /= b;
}

float fPower(float a, float b) {
    /* Function pangkat */
    /* Asumsi b adalah int */
    /* Mengembalikan value a ^ b */

    float aPowb;

    aPowb = a;

    for (int i = 2; i <= b; i++) {
        pTimes(&aPowb, a);
    }

    return aPowb;

}

void pPower(float *a, float b) {
    /* Procedure pangkat */
    /* Asumsi b adalah int */
    /* I.S. a dan b terdefinisi dan tidak sembarang */
    /* F.S. a menjadi a ^ b */

    float aPowb;

    aPowb = *a;

    for (int i = 2; i <= b; i++) {
        pTimes(&aPowb, *a);
    }

    *a = aPowb;

}

float fx(int degree, float coeff[degree], float x) {

    float fx;

    fx = coeff[0];

    for (int j = 1; j < degree; j++) {
        fx += coeff[j] * fPower(x, j);
    }

    return fx;

}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */

    printf("Riemann Sum Integral Approximation\n");
    printf("Polynomial Function\n");

    printf("\n");

    /* Setting up the function */

    int degree;

    printf("Degree of polynomial: ");
    scanf("%d", &degree);

    printf("\n");

    degree = fPlus(degree, 1);

    /* Input coefficient for each x^n and constant */

    float coeff[degree];

    for (int i = fMin(degree, 1); i >= 0; i--) {
        switch (i) {
            case 0:
                printf("Constant: ");
                break;
            case 1:
                printf("Coefficient of x: ");
                break;
            default:
                printf("Coefficient of x^%d: ", i);
                break;
        }

        scanf("%f", &coeff[i]);
    }

    printf("\n");

    /* Setting up the Riemann sum for integral approximation */
    /* Setting lower and upper bound of integral and number of rectangle(s) */
    float a, b, deltax;
    int n;

    printf("Lower bound: ");
    scanf("%f", &a);

    printf("Upper bound: ");
    scanf("%f", &b);

    printf("Number of rectangles: ");
    scanf("%d", &n);

    deltax = fDivide(fMin(b, a), n);

    /* Choosing Riemann sum method */

    int riemannMethod;

    printf("\n");

    printf("Choose a Riemann sum method\n");
    printf("--------------------------------------------------------------------\n");
    printf("1: Left Riemann Sum\n");
    printf("2: Midpoint Riemann Sum\n");
    printf("3: Right Riemann Sum\n");
    printf("--------------------------------------------------------------------\n");
    printf("Method: ");
    scanf("%d", &riemannMethod);

    /* Calculating the Riemann sum */

    float riemannSum = 0;

    for (int j = 1; j <= n; j++) {

        if (riemannMethod == 1) {
            pPlus(&riemannSum, fx(degree, coeff, fPlus(a, fTimes(fMin(j, 1), deltax))));
        } else if (riemannMethod == 2) {
            pPlus(&riemannSum, fx(degree, coeff, fPlus(a, fTimes(fMin(j, 1), deltax))));
            riemannSum += fx(degree, coeff, fDivide(fPlus(a, fTimes(fMin(j, 1), deltax)) + fPlus(a, fTimes(j, deltax)), 2));
        } else if (riemannMethod == 3) {
            riemannSum += fx(degree, coeff, fPlus(a, fTimes(j, deltax)));
        }

    }

    printf("\n");

    /* Displaying the result */

    printf("Result: %f", fTimes(deltax, riemannSum));

    return 0;
}