// Heap Intro

/*
Index starts from '1'
*/

#include<iostream>

// for using heap inbuilt function in STL
#include<queue>

using namespace std;

// Max Heap
class Heap {
    public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    // TC : O(logn)
    void insert(int val) {
        size = size + 1;

        // `val` ko store karna hai
        int index = size;
        arr[index] = val;

        // `val` ko shi index pe laana hai
        while(index > 1) {
            int parent = index/2;

            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else { // 'val' shi jagah pe pahuch gya hai
                return;
            }
        }
    }

    // TC : O(n)
    void deleteFromHeap() { // always deletes the root element
        if(size == 0) {
            cout << "nothing to delete !" << endl;
            return;
        }

        // put last node into first index
        arr[1] = arr[size];

        // remove last node by doing "size = size - 1"
        size = size - 1;

        // take root node to its correct position
        // TC : O(n)
        int i = 1;
        while(i < size) {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if((leftIndex <= size && rightIndex <= size) && (arr[i] < arr[leftIndex] && arr[i] < arr[rightIndex])) { // dono child (l & r) bda hai parent se
                int maxIndex = (arr[leftIndex] > arr[rightIndex]) ? leftIndex : rightIndex;
                swap(arr[i], arr[maxIndex]);
                i = maxIndex;
            }
            else if (leftIndex <= size && arr[i] < arr[leftIndex]) { // left child bda hai
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex <= size && arr[i] < arr[rightIndex]) { // right child bda hai
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else {
                return;
            }
        }
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// placing element at i-th index to its correct position in heap, TC : O(logn)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// TC : O(n logn)
void heapSort(int arr[], int n) { // input me max heap leta hai
    int size = n;
    while(size > 1) { // O(n)
        // step-1: swap root and last node
        swap(arr[1], arr[size]);
        size = size - 1;

        // step-2: heapify root node
        heapify(arr, size, 1); // O(logn)
    }
}

int main() {
    /*
    // Heap h;

    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);

    // h.insert(100);
    // h.insert(30);
    // h.insert(70);
    // h.insert(20);
    // h.insert(10);
    // h.insert(5);
    // h.insert(6);

    // h.insert(100);
    // h.insert(20);
    // h.insert(5);

    // int arr[6] = {-1, 54, 53, 55, 52, 50};
    // int n = 5; // size of array

    int arr[8] = {-1, 40, 30, 25, 55, 90, 100, 60};
    int n = 7; // size of array

    // making array to heap (building heap), TC : O(n)
    for(int i = n/2; i >= 1; i--) {
        heapify(arr, n, i);
    }

    cout << "printing the array now" << endl;

    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // heapSort(), TC : O(n logn)
    heapSort(arr, n);
    
    cout << "printing the sorted array" << endl;

    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // h.print();

    // h.deleteFromHeap();
    
    // h.print();
    */





    // /*
    cout << endl << "using Priority Queue" << endl;

    // max heap
    // priority_queue<int> pq;
    
    // pq.push(4);
    // pq.push(2);
    // pq.push(5);
    // pq.push(3);

    // cout << "element at top : " << pq.top() << endl;
    // pq.pop();
    // cout << "element at top : " << pq.top() << endl;
    // cout << "size : " << pq.size() << endl;
    // cout << "is Empty ? " << pq.empty() << endl;



    // min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout << "element at top : " << minHeap.top() << endl;
    minHeap.pop();
    cout << "element at top : " << minHeap.top() << endl;
    cout << "size : " << minHeap.size() << endl;
    cout << "is Empty ? " << minHeap.empty() << endl;
    // */

    return 0;
}