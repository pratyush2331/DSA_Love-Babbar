// Insertion Sort

/*
Time Complexity-
    Best Case : O(n)
    Worst Case: O(n^2)
*/

/*
sample i/p:
1
7
10 4 -1 0 0 5 121
sample o/p:
-1 0 0 4 5 10 121 
*/

#include<iostream>
using namespace std;

// right side se element utha ke left side ke correct index me daaldo
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {                // For Number of Pass = n-1
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > temp) {        // Checking for need of Shifting
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
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

        insertionSort(arr, n);

        display(arr, n);
    }
    return 0;
}