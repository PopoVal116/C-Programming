#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void append(struct node **head, int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct node *head = NULL;
    int value;

    printf("Введите элементы списка:\n");
    while (1) {
        scanf("%d", &value);
        if (value == 0) break;
        append(&head, value);
    }

    printf("Список: ");
    printList(head);

    freeList(head);
    return 0;
}