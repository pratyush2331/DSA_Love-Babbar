// reversing all the elements in the original array without using additional array

#include<iostream>
using namespace std;

// display function
void display(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// reverse func
void reverse(int arr[], int size) {
    int start = 0;
    int end = size-1;
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int brr[6] = {1,2,3,4,5,6};

    display(arr, 5);
    reverse(arr, 5);
    display(arr, 5);

    cout<<endl;

    display(brr, 6);
    reverse(brr, 6);
    display(brr, 6);

    return 0;
}