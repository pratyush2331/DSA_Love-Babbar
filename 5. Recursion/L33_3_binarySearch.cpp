// binary search using recursion

#include<iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int key) {
    // base case - 1
    if(s > e)  
        return -1;

    int mid = s + (e-s)/2;

    // base case - 2
    if(key == arr[mid]) 
        return mid;

    // recurrence relation
    if(key > arr[mid]) {
        binarySearch(arr, mid+1, e, key);
    }
    else {
        binarySearch(arr, s, mid-1, key);
    }
}

int main() {
    int arr[] = {1,2,5,9,10,11};

    int key = 0;

    cout << key << " found at index : " << binarySearch(arr, 0, 6, key) << endl;
    
    return 0;
}