// Insertion Sort using recursion

#include<iostream>
using namespace std;

void insertionSort(int arr[], int idx, int n) {
    // base case
    if(idx == n)
        return;

    int curr = arr[idx];
    int j = idx - 1;

    while(j >= 0 && curr < arr[j]){
            arr[j+1] = arr[j];
            j--;
    }
    arr[j + 1] = curr; //place curr element at correct place

    // one part Done recursion will do other work;
    insertionSort(arr , idx + 1 , n);
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int arr[15];
        int n;
        cin>>n;

        for(int i = 0; i < n; i++) {
            cin>>arr[i];
        }

        insertionSort(arr, 1, n);

        display(arr, n);
    }
    return 0;
}