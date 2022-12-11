#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100], word[100], twoD[10][30], *token, word2[1000];
    const char pemisah[2] = " ";
    int jumlah = 0;
    int jumlah2 = 0;

    printf("Enter the string:\n");
    gets(str);
    str[strcspn(str, "\n")] = 0;
    printf("Enter the word to be removed:\n");
    gets(word);

    token = strtok(str, pemisah);
    // Menghitung kata 
    int i = 0;
    printf("The words before removing: ");
    while (token != NULL)
    {
        strcpy(twoD[i], token);
		token = strtok (NULL, pemisah);
		jumlah++;
        i++;
    }
    printf("%d\n", jumlah);

    for (int i = 0; i < jumlah; i++){
		if (strcmp(twoD[i], word) == 0){
			twoD[i][0] = '\0';
		}
	}

	for (int i = 0; i < jumlah; i++){
		if (twoD[i][0] == '\0'){
			continue;
		} else{
			strcat(word2, twoD[i]);
			strcat(word2, " ");
			jumlah2++;
		}
	}

    printf("\n");
    printf("The strings After removing: ");
    puts(word2);
    printf("The words After removing: ");
    printf("%d\n", jumlah2);
    return 0;
}