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

float polynomial(int degree, float coeff[degree], float x) {

    float px;

    px = coeff[0];

    for (int j = 1; j < degree; j++) {
        px += coeff[j] * fPower(x, j);
    }

    return px;

}

void swap(float *a, float *b) {
    float c = *a;

    *a = *b;
    *b = c;
}

int main() {
    /* Buatlah kalkulator integral menggunakan konsep Integral Riemann */
    /* Notes: Penggunaan operator aritmatika harus menggunakan fungsi dan 
              prosedur yang telah didefinisikan dan diimplementasi sebelumnya */
    /* Input dan output dibebaskan kepada Cakru URO 14 */
    /* Batasan: Derajat dari koefisien adalah whole number {0, 1, 2, ...} */

    printf("Riemann Sum Integral Approximation\n");
    printf("Polynomial Function\n");
    printf("p(x) = a0 + a1.x + a2.x^2 + ... + an.x^n");

    printf("\n");

    /* Setting up the function */

    int degree;

    printf("\n");

    printf("Degree of polynomial: ");
    scanf("%d", &degree);

    printf("\n");

    degree = fPlus(degree, 1);
    // As array in C starts from 0, and we'll be using the degree for the index of array of coefficient as well, the +1 is needed

    /* Input coefficient for each x^i {i = [0, degree - 1]} and constant */

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

    /* Setting the new degree if some of the highest degree is zero */
    int k = fMin(degree, 1);

    while (k > 0 && coeff[k] == 0) {
        k = fMin(k, 1);
    }

    bool degree_change = false;

    if (fMin(degree, 1) != k) {
        degree_change = true;
    }

    degree = fPlus(k, 1);

    /* Displaying the polynomial function p(x) */

    if (degree_change == true) {
        printf("Some of the input is not valid, making the degree of function decreases.\n");
        printf("Degree of polynomial: %.0f\n", fMin(degree, 1));   
    }

    printf("p(x) = ");

    for (int i = 0; i < degree; i++) {
        if (i == 0) {
            if (degree == 1) {
                printf("%.f", coeff[i]);
            } else {
                if (coeff[i] == 0) {
                } else {
                    printf("%.f + ", coeff[i]);
                }
            }
        } else if (i > 0 && i < fMin(degree, 1)) {
            if (coeff[i] == 0) {
            } else if (coeff[i] == 1) {
                if (i == 1) {
                    printf("x + ", i);
                } else {
                    printf("x^%d + ", i);
                }
            } else {
                if (i == 1) {
                    printf("%.fx + ", coeff[i], i);
                } else {
                    printf("%.fx^%d + ", coeff[i], i);
                }
            }
        } else {
            if (coeff[i] == 0) {
            } else if (coeff[i] == 1) {
                if (i == 1) {
                    printf("x", i);
                } else {
                    printf("x^%d", i);
                }
            } else {
                if (i == 1) {
                    printf("%.fx", coeff[i], i);
                } else {
                    printf("%.fx^%d", coeff[i], i);
                }
            }      
        }
    }

    printf("\n");

    /* Setting up the Riemann sum for integral approximation */
    /* Setting lower and upper bound of integral and number of rectangle(s) */
    float a, b, deltax;
    int n;

    printf("\n");

    printf("Lower bound: ");
    scanf("%f", &a);

    printf("Upper bound: ");
    scanf("%f", &b);

    bool reverse = false;

    if (a > b) {
        swap(&a, &b);

        reverse = true;
    }

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
    
    /* Anticipating error of non-valid options */

    while (riemannMethod > 3 || riemannMethod < 1) {
        printf("Method: ");
        scanf("%d", &riemannMethod);

        if (riemannMethod > 3 || riemannMethod < 1) {
            printf("\n");

            printf("Please input a valid option.\n");
        }
    }

    /* Calculating the Riemann sum */

    float riemannSum = 0;

    for (int j = 1; j <= n; j++) {

        if (riemannMethod == 1) {
            pPlus(&riemannSum, polynomial(degree, coeff, fPlus(a, fTimes(fMin(j, 1), deltax))));
        } else if (riemannMethod == 2) {
            pPlus(&riemannSum, polynomial(degree, coeff, fDivide(fPlus(fPlus(a, fTimes(fMin(j, 1), deltax)), fPlus(a, fTimes(j, deltax))), 2)));
        } else if (riemannMethod == 3) {
            pPlus(&riemannSum, polynomial(degree, coeff, fPlus(a, fTimes(j, deltax))));
        }

    }

    printf("\n");

    /* Displaying the result */

    if (reverse == true) {
        pTimes(&riemannSum, -1);
    }

    printf("Result: %.4f", fTimes(deltax, riemannSum));

    return 0;
}