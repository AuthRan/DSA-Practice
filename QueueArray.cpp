#include <iostream>
using namespace std;

class Queue {
private:
    int front;
    int rear;
    int size;
    int *q;

public:
    Queue(int size){front=rear=-1; this->size = size; q = new int[this->size];}
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x) {
    if(rear == size-1) {
        cout<<"Queue is full"<<endl;
    }
    else {
        rear++;
        q[rear] = x;
    }
}
int Queue::dequeue() {
    int x = -1;
    if(front == rear) {
        cout<<"Queue is empty"<<endl;
    }
    else {
        x = q[front+1];
        front++;
    }
    return x;
}

void Queue::display() {
    for(int i=front+1; i<=rear; i++) {
        cout<<q[i]<<" ";
    }
}

int main (int argc, char *argv[]) {
    Queue que(5);
    que.enqueue(10);   
    que.enqueue(20);   
    que.enqueue(30);   
    que.enqueue(40);
    que.display();   
    return 0;
}