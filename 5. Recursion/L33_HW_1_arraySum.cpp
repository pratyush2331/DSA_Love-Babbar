// array sum

#include<iostream>
using namespace std;

int arraySum(int arr[], int n) {
    // base case
    if(n == 0) return 0;
    if(n == 1) return arr[0];

    return arr[0] +  arraySum(arr+1, n-1);
}

int main() {
    int n;
    cin >> n;

    int* arr = new int [n];
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << " Array Sum = " << arraySum(arr, n) << endl;

    delete[] arr;

    return 0;
}