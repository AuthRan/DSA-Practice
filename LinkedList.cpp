#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void createLinkedList(int arr[], int n)
{
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void displayLinkedList(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL");
}

void RdisplayLinkedList(struct Node *p)
{
    if (p != NULL)
    {
        // printf("%d ", p->data);
        // RdisplayLinkedList(p->next);
        RdisplayLinkedList(p->next);
        printf("%d ", p->data);
    }
}

int count(struct Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int Rcount(struct Node *p)
{
    if (p)
    {
        return Rcount(p->next) + 1;
    }
    else
    {
        return 0;
    }
}

int Rmin(struct Node *p)
{
    int min = INT_MAX;
    if (!p)
    {
        return INT_MAX;
    }
    min = Rmin(p->next);
    if (min > p->data)
    {
        min = p->data;
    }
    return min;
}

struct Node *Search(struct Node *p, int key)
{
    while (p)
    {
        if (key == p->data)
        {
            printf("Yes!");
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void insert(struct Node **head, int n, int x, int index)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = *head;
    int i = 0;
    if (index >= 0 && index <= n)
    {
        if (index == 0)
        {
            t->data = x;
            t->next = *head;
            *head = t;
        }
        else
        {
            while (i < index - 1)
            {
                i++;
                p = p->next;
            }
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

void deleteNode(struct Node *p, int index)
{
    struct Node *t, *q = NULL;
    if (index >= 1 && index <= count(p))
    {
        if (index == 1)
        {
            p = head;
            head = p->next;
            free(p);
        }
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            free(p);
        }
    }
    return;
}

void duplicateRemover(struct Node *p)
{
    struct Node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void reverseThreePointer(struct Node *p) {
    struct Node *q = NULL, *r = NULL;
    while(p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

int main()
{
    int arr[] = {11, 13, 18, 12, 71, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    createLinkedList(arr, n);
    // insert(&head, n, 99, 0);
    // deleteNode(head, 3);
    // duplicateRemover(head);
    reverseThreePointer(head);
    displayLinkedList(head);

    // RdisplayLinkedList(head);
    // printf("Length of list is %d", Rcount(head));
    // printf("Min is %d", Rmin(head));
    // printf("%d", Search(head, 10));
}