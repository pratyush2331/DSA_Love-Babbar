// Quick Sort
// GFG : https://practice.geeksforgeeks.org/problems/quick-sort/1

/*
TC:-
Best Case : O(n logn)
Avg Case : O(n logn)
Worst Case : O(n^2)

SC : O(logn)
*/

#include<iostream>
using namespace std;


void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int s, int e) {
    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i <= e; i++) {
        if(arr[i] <= pivot) {
            cnt++;
        }
    }

    // pivot place ka right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]); // pivot ko sahi jagah me place kardiye

    // left and right wala part sambhal lete h
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    // base case
    if(s >= e) return ;
    
    // partition
    // p is pivotIndex
    int p = partition(arr, s, e); // pivot ko sahi jagah me place karke aagaya
    
    // printArray(arr, e-s);
    
    // left part sort karo
    quickSort(arr, s, p-1);

    // right part sort karo
    quickSort(arr, p+1, e);
}


int main() {
    int arr[] = {13, 34, 22, 19, 8, 3, 4};
    int n = sizeof(arr)/sizeof(int);

    quickSort(arr, 0, n-1);

    printArray(arr, n);

    return 0;
}
