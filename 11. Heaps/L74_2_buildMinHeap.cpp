// Build Min Heap
// CodeStudio : https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167?leftPanelTab=0

/*
TC of the whole process : O(n) * O(logn) = O(n logn)
*/

/*
Index starts from '0'
*/

#include<bits/stdc++.h>
using namespace std;

// placing element at i-th index to its correct position in heap, TC : O(logn)
void heapify(vector<int> &arr, int n, int i) {
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if(smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here

    // making array to heap (building heap), TC : O(n)
    int n = arr.size();
    for(int i = n/2-1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    return arr;
}

int main() {
    
    return 0;
}