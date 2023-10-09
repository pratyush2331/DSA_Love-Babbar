// find unique element

/*
Input:         1 2 3 4 5 4 3 2 1
Output:        5
*/

// XOR   ---->    unique element

#include<iostream>
using namespace std;

void findUnique(int arr[], int size) {
    int ans = 0;
    for(int i = 0; i < size; i++) {
        ans = ans ^ arr[i];
    }
    cout<<ans<<endl;
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[9] = {1,2,3,4,5,4,3,2,1};
    printArray(arr, 9);
    findUnique(arr, 9);
    return 0;
}
