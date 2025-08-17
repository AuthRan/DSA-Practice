#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
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

void RdisplayLinkedList(struct Node *p) {
    if(p != NULL) {
        // printf("%d ", p->data);
        // RdisplayLinkedList(p->next);
        RdisplayLinkedList(p->next);
        printf("%d ", p->data);
    }
}

int count(struct Node *p) {
    int count = 0;
    while(p){
        count++;
        p= p->next;
    }
    return count;
}

int Rcount(struct Node *p) {
    if(p){
        return Rcount(p->next) +1;
    }
    else {
        return 0;
    }
}

int Rmin(struct Node *p) {
    int min = INT_MAX;
    if(!p){
        return INT_MAX;
    }
    min = Rmin(p->next);
    if(min > p->data){
        min = p->data;
    }
    return min;
}

int main() {
    int arr[] = {11,13,14,12,10,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    createLinkedList(arr, n);
    // displayLinkedList(head);
    // RdisplayLinkedList(head);
    // printf("Length of list is %d", Rcount(head));
    printf("Min is %d", Rmin(head));

}