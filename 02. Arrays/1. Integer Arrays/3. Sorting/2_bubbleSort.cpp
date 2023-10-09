// Selection Sort

/*
Time Complexity
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

#include<bits/stdc++.h>
using namespace std;

// optimised bubble sort due to 'flag'
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++){          // For Number of Pass = n-1
        bool flag = 0;
        for(int j = 0; j < n-1-i; j++) {   // For Number of Comparison = n-1-i
            if(arr[j] > arr[j+1]) {        // Checking for need of Swapping
                flag = 1;
                swap(arr[j], arr[j+1]);
            }
        }
        if(flag == 0)                      // Check for No Swapping (flag == 0) in any pass
            break;
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

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        bubbleSort(arr, n);

        display(arr, n);
    }
    return 0;
}