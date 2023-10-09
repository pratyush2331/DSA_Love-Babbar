// find pivot in a rotated sorted array

// array must be rotated sorted (in Input)
// elements can be repeated

/*
Sorted array         : 1 2 3 6 7 9
Rotated sorted array : 6 7 9 1 2 3

                9

            7

        6

                            3

                        2
                   ___
                  | 1 |  <---  pivot
                   ---
*/

#include<iostream>
using namespace std;

int getPivot(int arr[], int n);

int main() {

    // int arr[20] = {6, 7, 9, 1, 2, 3};
    int arr[20] = {7, 7, 2, 2, 2, 3};
    // int arr[20] = {6, 7, 1, 2, 3};
    // int arr[20] = {1, 2, 3, 4, 5, 0};

    int n = sizeof(arr)/sizeof(arr[0]);
    // cin>>n;

    // for(int i = 0; i < n; i++) {
    //     cin>>arr[i];
    // }

    cout<<"\nPivot Index = "<<getPivot(arr, n);
    return 0;
}

int getPivot(int arr[], int n) {
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    while(s < e) {
        if(arr[mid] >= arr[0]) s = mid+1;
        else e = mid;
        mid = s + (e-s)/2;
    }
    return mid;
}
