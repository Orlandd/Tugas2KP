#include <stdio.h>
#include <string.h>

//Soal A No 1 

void main(){

    char merk[100];
    char space[] = " ";
    char serial[100];
    int lenght;

    printf("Merk handphone \t\t: ");
    gets(merk);
    printf("Serial handphone \t: ");
    gets(serial);
    
    printf("\n======================================\n");
    printf("\nMerk handphone \t\t: %s\n", merk);
    printf("Serial handphone \t: %s\n", serial);

    // Menggabungkan string
    strcat(merk, space);
    strcat(merk, serial);

    lenght = strlen(merk);
    printf("\n======================================\n");
    printf("\nHandphone \t: %s\n", merk);
    printf("panjang \t: %d karakter", lenght);

}
