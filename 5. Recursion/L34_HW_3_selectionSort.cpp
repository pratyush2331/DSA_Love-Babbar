// Selection Sort using Recursion

#include<iostream>
using namespace std;

void selectionSort(int arr[], int idx, int n){
    // base case
    if(idx == n) {
        return ;
    }

    // processing
    int minIndex = idx;
    for(int i = idx + 1; i < n; i++) {
        if(arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    swap(arr[idx], arr[minIndex]);

    // recurrence relation
    selectionSort(arr, idx+1, n);
}

void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int arr[15];
        int n;
        cin>>n;

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        selectionSort(arr, 0, n);

        display(arr, n);
    }
    return 0;
}