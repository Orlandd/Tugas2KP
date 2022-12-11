#include <stdio.h>

void packCharacters(char krtr1, char krtr2);
void biner(unsigned nilai);
void unpack( unsigned value );


int LENGTH = 32;

int main(void) {
    char karakter1, karakter2, karakter3, karakter4;

    printf("input 4 characters: ");
    scanf("%c %c %c %c", &karakter1, &karakter2, &karakter3, &karakter4);
    printf("\nKarakter 1 dalam biner : ");
    biner(karakter1);
    printf("\nKarakter 2 dalam biner : ");
    biner(karakter2);

    printf("\n\nPacked karakter dalam binner : \n");
    packCharacters(karakter1, karakter2); 

    printf("\nKarakter 3 dalam biner : ");
    biner(karakter3);
    printf("\nKarakter 4 dalam biner : ");
    biner(karakter4);

    printf("\n\nPacked karakter dalam binner : \n");
    packCharacters(karakter3, karakter4); 

}

void packCharacters(char krtr1, char krtr2) {
    unsigned pack;

    pack = krtr1;
    pack <<= 8;
    pack |= krtr2;

    printf("karakter - %d\n", pack);
    biner(pack);

    printf("\n");

    printf( "\n" );
    unpack( pack );


}

void biner(unsigned nilai) {
    printf("%7u = ", nilai);
    unsigned int c = 0;

    for(unsigned int i = 1 << (LENGTH -1) ; i > 0 ; i /= 2) {
        putchar((nilai & i ) != 0 ? '1' : '0');
        c++;

        if(c % 8 == 0) {
            printf(" ");
        }
    }

}


void unpack( unsigned value )
{
    char k1, k2;

    k1 = value;
    printf( "Character 2 unpacked: %c\n", k1 );

    value >>= 8;

    k2 = value;
    printf( "CHaracter 1 unpacked: %c\n\n", k2 );
}