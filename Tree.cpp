#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **q;

public:
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        q = new Node *[this->size];
    }
    ~Queue()
    {
        delete[] q;
    }
    void enqueue(Node *x);
    Node *dequeue();
    int isEmpty()
    {
        return (front == rear);
    }
    void display();
};

void Queue::enqueue(Node *x)
{
    if (rear == size - 1)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        rear++;
        q[rear] = x;
    }
}
Node *Queue::dequeue()
{
    Node *x = nullptr;
    if (front == rear)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        front++;
        x = q[front];
    }
    return x;
}

class Tree
{
public:
    Node *root;
    Tree() { root = nullptr; }
    void createTree();
    void preorder(Node *p);
};

void Tree::createTree()
{
    Node *p, *t;
    int x;
    Queue q(100);
    cout << "Enter value of root: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child of " << p->data << ":";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << ":";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }

    }
}

void Tree::preorder(Node *p) {
    if(p) {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main() {
    Tree t;
    t.createTree();
    t.preorder(t.root);
}