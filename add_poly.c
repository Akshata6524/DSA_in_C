#include <stdio.h>

struct poly {
    int co;  // Coefficient
    int ex;  // Exponent
};

int readpoly(struct poly p[]);
int addpoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]);
void displaypoly(struct poly p[], int terms);

int main() {
    struct poly p1[10], p2[10], p3[10];
    int t1, t2, t3;

    // Read first polynomial
    t1 = readpoly(p1);
    printf("\nFirst polynomial: ");
    displaypoly(p1, t1);

    // Read second polynomial
    t2 = readpoly(p2);
    printf("\nSecond polynomial: ");
    displaypoly(p2, t2);

    // Add both polynomials
    t3 = addpoly(p1, p2, t1, t2, p3);
    printf("\n\nResultant polynomial after addition: ");
    displaypoly(p3, t3);

    return 0;
}

int readpoly(struct poly p[]) {
    int t, i;
    printf("\nEnter total number of terms in the polynomial: ");
    scanf("%d", &t);

    printf("Enter COEFFICIENT and EXPONENT in DESCENDING ORDER:\n");
    for (i = 0; i < t; i++) {
        printf("Term %d - Coefficient: ", i + 1);
        scanf("%d", &p[i].co);
        printf("Term %d - Exponent: ", i + 1);
        scanf("%d", &p[i].ex);
    }
    return t;
}

int addpoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (p1[i].ex == p2[j].ex) {
            p3[k].co = p1[i].co + p2[j].co;
            p3[k].ex = p1[i].ex;
            i++; j++; k++;
        }
        else if (p1[i].ex > p2[j].ex) {
            p3[k].co = p1[i].co;
            p3[k].ex = p1[i].ex;
            i++; k++;
        }
        else {
            p3[k].co = p2[j].co;
            p3[k].ex = p2[j].ex;
            j++; k++;
        }
    }

    // Copy remaining terms
    while (i < t1) {
        p3[k].co = p1[i].co;
        p3[k].ex = p1[i].ex;
        i++; k++;
    }
    while (j < t2) {
        p3[k].co = p2[j].co;
        p3[k].ex = p2[j].ex;
        j++; k++;
    }

    return k;
}

void displaypoly(struct poly p[], int terms) {
    for (int k = 0; k < terms - 1; k++)
        printf("%d(x^%d) + ", p[k].co, p[k].ex);
    printf("%d(x^%d)", p[terms - 1].co, p[terms - 1].ex);
}
//output

Enter total number of terms in the polynomial: 3
Enter COEFFICIENT and EXPONENT in DESCENDING ORDER:
Term 1 - Coefficient: 3
Term 1 - Exponent: 3
Term 2 - Coefficient: 3
Term 2 - Exponent: 2
Term 3 - Coefficient: 4
Term 3 - Exponent: 1

First polynomial: 3(x^3) + 3(x^2) + 4(x^1)
Enter total number of terms in the polynomial: 2
Enter COEFFICIENT and EXPONENT in DESCENDING ORDER:
Term 1 - Coefficient: 4
Term 1 - Exponent: 2
Term 2 - Coefficient: 5
Term 2 - Exponent: 1

Second polynomial: 4(x^2) + 5(x^1)

Resultant polynomial after addition: 3(x^3) + 7(x^2) + 9(x^1)
