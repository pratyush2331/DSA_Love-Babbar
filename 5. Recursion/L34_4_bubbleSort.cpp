// Bubble Sort using recursion

#include<iostream>
using namespace std;

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int  arr[], int n) {
    // base case
    if(n == 0 || n == 1) {
        return ;
    }

    // processing
    // 1 case solve krlia - largest element ko end me rakh dega
    bool flag = 0;
    for(int i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
            flag = 1;
        }
    }
    if(flag == 0)
        return ;

    // recurrence relation
    bubbleSort(arr, n-1);
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int arr[15];
        int n;
        cin>>n;

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        bubbleSort(arr, n);

        display(arr, n);
    }
    return 0;
}