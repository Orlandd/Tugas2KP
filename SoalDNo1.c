#include <stdio.h>
#include <stdlib.h>

// Soal D No 1

struct node {
    int angka;
    struct node *next;
} *head;


void reverseList(struct node **head_);
void tampilList(struct node *head_);
void push(struct node **head_, int new_data);

int main(void) {

    struct node *head = NULL;
    
    for (int i = 1 ; i <= 10 ; i++) {
    push(&head, i);
    }

    printf("List awal : \n");
    tampilList(head);
    reverseList(&head);

    printf("\nList setelah di reverse : \n");
    tampilList(head);
}

void tampilList(struct node *head) {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d", temp->angka);
        temp = temp->next;
    }
}

void tambahList(int n ) {
    struct node *newNode, *temp;

    int num, i;

    head = (struct node*)malloc(sizeof(struct node));

    for(int i = 0; i < 10 ; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));

        newNode->angka = i+1;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
}

void push(struct node **head_, int new_data) {
    struct node *new_node ;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->angka = new_data;
    new_node->next = *head_;
    *head_ = new_node;
}

void reverseList(struct node **head_) {
    struct node *sebelumNode, *curNode, *next;

    if(*head_ != NULL) {
        sebelumNode = NULL;
        curNode = *head_;
        next = NULL;

        while(curNode != NULL) {
            next = curNode->next;
            curNode->next = sebelumNode;

            sebelumNode = curNode;
            curNode = next;
        }
        *head_ = sebelumNode;
    }

}
