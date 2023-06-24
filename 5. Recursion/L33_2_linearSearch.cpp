// linear search using recursion

#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool linearSearch(int arr[], int n, int key) {
    // printArray(arr, n);

    // base case
    if(n == 0) return 0;

    if(arr[0] == key)
        return 1;
    
    return linearSearch(arr+1, n-1, key);
}

int main() {
    int arr[] = {11, 0, 123, 2, 432, 1};

    int key = 0;

    cout << endl;
    cout << key << " is present or not : " << linearSearch(arr, 6, key) << endl;
    
    return 0;
}