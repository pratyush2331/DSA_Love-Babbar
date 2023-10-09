// Linear Search Quesiton

/*
TC: O(n)
SC: O(1)
*/

#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            return i;
        }
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
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        int key;
        cin>>key;
        cout<<linearSearch(arr, n, key)<<endl;
    }
    return 0;
}