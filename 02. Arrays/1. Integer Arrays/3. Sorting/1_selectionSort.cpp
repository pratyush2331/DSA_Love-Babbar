// Selection Sort

/*
Time Complexity
    Best Case : O(n^2)
    Worst Case: O(n^2)
*/

/*
sample i/p:
1
7
10 4 -1 0 0 5 121
sample i/p:
-1 0 0 4 5 10 121 
*/

#include<bits/stdc++.h>
using namespace std;

// right se sabse chota element select krke left me bhej do
void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++) {                // for number of passes = n-1
        int min_index = i;
        for(int j = i+1; j < n; j++) {            // for finding minimum element from (i+1) to last index
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);             // swapping element in i-th with min_index index
    }
}

// not important
void stableSelectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++) {
        int min_index = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        int key = arr[min_index];                   // acting as a temp to store the ele at min_index
        while(min_index > i) {                      // it'll shift all the ele from i to min_index INSTEAD of SWAPPING
            arr[min_index] = arr[min_index - 1];
            min_index--;
        }
        arr[min_index] = key; // OR arr[i] = key;
        
    }
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

        selectionSort(arr, n);

        // stableSelectionSort(arr, n);

        display(arr, n);
    }
    return 0;
}