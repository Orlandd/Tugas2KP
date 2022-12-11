#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
int stack [50], front = 0;

void push(char a) {
    top++;
    stack[top] = a;
}

void pop(){
    top--;
}

int palindrome (char s[]) {
    int i;
    char b;

    for(i - 0; s[i] != '\0'; i++) {
        b = s[i];
        push(b);
    }

    for(i = 0 ; i < strlen(s)/2; i++) {
        if (stack[top] == stack[front])
            {
                pop();
                front++;
            }
            else
            {
                return 0;
            }
        }

    if ((strlen(s) / 2)  ==  front){
        return 1;
    }

}

int main(void) {
    char s[] = "madam";
    printf("Text : ");
    puts(s);

    if (palindrome(s)) {
        printf("Yes is palindrome");
    }
    else {
        printf("No is palindrome");
    }

}