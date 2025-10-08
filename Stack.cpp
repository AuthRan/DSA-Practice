#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Stack {
private:
    Node *top;
public:
    Stack() {
        top = NULL;
    }
    void push(Stack *, int);
    int pop(Stack *);
    void display(Stack s) {
        Node *p = new Node;
        p = top;
        while(p!=NULL) {
            cout<<p->data<<" ";
            p = p->next;
        }
    }
};
void Stack::push(Stack *s, int x) {
    Node *t = new Node;
    t->data = x;
    t->next = top;
    top = t;
}
int Stack::pop(Stack *s) {
    Node *p = new Node;
    p = top;
    top = p->next;
    int x = p->data;
    free(p);
    return x;
}
int main (int argc, char *argv[]) {
    Stack s;
    s.push(&s, 10);
    s.push(&s, 20);
    s.push(&s, 30);
    cout<<s.pop(&s)<<endl;
    s.display(s);
    return 0;
}