#include <stdio.h>
#include <stdlib.h>

void main() {
    int x;
    printf("Ukuran Array : ");
    scanf("%d", &x);
    int *array = (int*)malloc(sizeof(int)*x);

    for(int i = 0; i < x; i++) {
        printf("Array %d : ", i);
        scanf("%d", &array[i]);
    }

    printf("\nIsi Array\n");
    for(int i = 0; i < x; i++) {
        printf("Array %d : %d\n", i ,array[i]);
    }

    printf("\nIsi Array setelah realloc\n");
    array = realloc(array, x/2);
    for(int i = 0; i < x/2; i++) {
        printf("Array %d : %d\n", i ,array[i]);
    }
}