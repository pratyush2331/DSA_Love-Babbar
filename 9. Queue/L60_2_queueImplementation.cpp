// Queue implementation
// CodeStudio : https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTab=1

#include<iostream>
using namespace std;

#include <bits/stdc++.h> 
class Queue {
    int* arr;
    int size;
    int qfront;
    int rear;

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear) {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int data) {
        if(rear == size) {
            cout << "Queue is full" << endl;
        }
        else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(isEmpty()) {
            return -1;
        }
        else {
            int temp = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return temp;
        }
    }

    int front() {
        if(isEmpty()) {
            return -1;
        }
        return arr[qfront];
    }
};

int main() {
    
    return 0;
}