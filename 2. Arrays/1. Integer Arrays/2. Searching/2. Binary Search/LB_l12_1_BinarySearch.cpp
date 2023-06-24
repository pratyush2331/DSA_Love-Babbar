// Binary Search
// only works in sorted array

/*
Time Complexity-
    Best Case : O(1)      <----    When the element is at mid position
    Worst Case: O(logn)
*/

/*
Test Case-
    Input_1 : 
            5 0
            1 2 3 4 5
    Output_1: 
            -1

    Input_2 : 
            5 4
            1 2 3 4 5
    Output_2: 
            3
*/

#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int start = 0, end = n-1;
    int mid = start + (end - start)/2;
    while(start <= end){          // =, agar ek hi ele rha to
        if(key == arr[mid]){
            return mid;
        }
        if(key > arr[mid]){
            start = mid + 1;
        }
        else{ 
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int arr[10];

        int n;
        cin>>n;

        int key;
        cin>>key;

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        cout << binarySearch(arr, n, key) << endl;
    }
    return 0;
}