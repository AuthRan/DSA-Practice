#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
}*head = NULL;

void createLinkedList(int arr[], int n) {
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head -> data = arr[0];
    head -> next = NULL;
    last = head;

    for (int i = 1; i<n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = arr[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void displayLinkedList(struct Node *p) {
    while (p != NULL) {
        printf("%d->", p->data);
        p = p -> next;
    }
    printf("NULL");
}

int main() {
    int arr[] = {1,3,4,2,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    createLinkedList(arr, n);
    displayLinkedList(head);
}