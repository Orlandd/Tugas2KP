#include <stdio.h>
#define MINIMUM2(a,b) (a < b ? a : b)
#define MINIMUM3(a,b,c) MINIMUM2(MINIMUM2(a,b), c)

// Soal E No 1

int main(void) {
    int n1, n2, n3;
    int calc;

    printf("Enter 3 numbers : ");
    scanf("%d %d %d", &n1, &n2, &n3);
    calc = MINIMUM3(n1, n2, n3);

    printf("smallest number : %d\n", calc);
}
