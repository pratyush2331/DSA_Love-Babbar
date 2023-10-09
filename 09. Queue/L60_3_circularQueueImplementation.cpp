// Circular Queue Implementation
// CodeStudio : https://www.codingninjas.com/codestudio/problems/circular-queue_1170058?leftPanelTab=2

#include<iostream>
#include<queue>
using namespace std;

class CircularQueue{
    int* arr;
    int size;
    int front;
    int rear;

    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if( rear == (front-1)%(size-1) ) {
            // cout << "Queue is full" << endl;
            return false;
        }
        if(front == -1) {
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1) {
            // cout << "Queue is empty" << endl;
            return -1;
        }
        int temp = arr[front];
        arr[front] = -1;
        if(front == rear) { // single element
            front = rear = -1;
        }
        else if(front == size-1) {
            front = 0;
        }
        else {
            front++;
        }
        return temp;
    }
};

int main() {
    
    return 0;
}