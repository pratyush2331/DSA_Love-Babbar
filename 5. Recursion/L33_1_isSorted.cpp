// Check if an array is sorted using recursion

#include<iostream>
using namespace std;

int isArraySorted(int arr[], int n) {
    if(n == 0 || n == 1) 
        return 1;
    
    if(arr[0] > arr[1]) {
        return 0;
    }
    else {
        return isArraySorted(arr+1, n-1);
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,7,8};

    cout << "sorted or not ? " << isArraySorted(arr, 9) << endl;
    
    return 0;
}