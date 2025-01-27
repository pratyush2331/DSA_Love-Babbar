// array

#include<bits/stdc++.h>
using namespace std;

// void printArray(int* arr, int n) {
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10];

    // Q. array me 
    // arr[0] --> 1
    // arr[1] --> 4
    // arr[2] --> 7
    // arr[3] --> 10
    // arr[4] --> 13
    // ...

    int diff = 3;
    arr[0] = 1;
    for(int i = 1; i < 10; i++) {
        arr[i] = arr[i-1] + diff;
    }

    // printing
    printArray(arr, 10);
    
    return 0;
}