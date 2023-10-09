// Binary Seacrh Application
// First & Last Occurrence of an element

#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int key);
int lastOcc(int arr[], int n, int key);

int main(){
    int t;
    cin>>t;

    while(t--) {
        int arr[20];
        int n;
        cin>>n;

        int key;
        cin>>key;

        for(int i = 0; i < n; i++) {
            cin>>arr[i];
        }

        cout<<firstOcc(arr, n, key)<<" "<<lastOcc(arr, n, key)<<endl;
    }
    return 0;
}

int firstOcc(int arr[], int n, int key) {
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;

    int ans = -1;
    while(s <= e) {             // for n == 1
        if(key == arr[mid]) {
            ans = mid;
            e = mid-1;
        }
        else if(key > arr[mid]) {
            s = mid+1;
        }
        else {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int key) {
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;

    int ans = -1;
    while(s <= e) {             // for n == 1
        if(key == arr[mid]) {
            ans = mid;
            s = mid+1;
        }
        else if(key > arr[mid]) {
            s = mid+1;
        }
        else {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}