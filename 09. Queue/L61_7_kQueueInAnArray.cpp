// Implement k Queue in an array

#include<iostream>
using namespace std;

class kQueue {
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;

  public:
    kQueue(int n, int k) {
        this->n = n;
        this->k = k;
        
        arr = new int[n];
        
        front = new int[k];
        rear = new int[k];
        for(int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for(int i = 0; i < n; i++) {
            next[i] = i+1;
        }
        next[n-1] = -1;
        
        freeSpot = 0;
    }

    void enqueue(int data, int qn) {
        // overflow
        if(freeSpot == -1) {
            cout << "No empty slot is present" << endl;
        }

        // find first free index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // check whether first element
        if(front[qn-1] == -1) {
            front[qn-1] = index;
        }
        else {
            // link new element to the prev element
            next[rear[qn-1]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qn-1] = index;

        // push element
        arr[index] = data;
    }

    int deque(int qn) {
        // underflow
        if(front[qn-1] == -1) {
            cout << "Queue underflow" << endl;
            return -1;
        }

        // find index to pop
        int index = front[qn-1];

        // front ko aage badhao
        front[qn-1] = next[index];

        // free slot ko manage karo
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main() {
    kQueue q(10, 3);

    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout << q.deque(1) << endl;
    cout << q.deque(2) << endl;
    cout << q.deque(1) << endl;
    cout << q.deque(1) << endl;

    cout << q.deque(1) << endl;
    
    return 0;
}