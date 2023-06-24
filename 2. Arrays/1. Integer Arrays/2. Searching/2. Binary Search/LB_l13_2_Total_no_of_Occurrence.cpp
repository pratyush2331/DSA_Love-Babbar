// Binary Seacrh Application
// Total Number of Occurrence of an element

#include<iostream>
using namespace std;

int firstOccurrence(int arr[], int size, int key)
{
    int start = 0, end = size-1;
    int mid;
    int ans = -1;
    while(start <= end){
        mid = start + (end-start)/2;

        if(key == arr[mid]){
            ans = mid;
            end = mid-1;;
        }
        else if(key > arr[mid])
            start = mid+1;
        else
            end = mid-1;
    }
    return ans;
}

int lastOccurrence(int arr[], int size, int key)
{
    int start = 0, end = size-1;
    int mid;
    int ans = -1;
    while(start <= end){
        mid = start + (end-start)/2;

        if(key == arr[mid]){
            ans = mid;
            start = mid+1;
        }
        else if(key > arr[mid])
            start = mid+1;
        else
            end = mid-1;
    }
    return ans;
}

int main(){
    int arr[30];

    int size;
    cin>>size;

    int key;
    cin>>key;

    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    int first = firstOccurrence(arr, size, key);
    int last = lastOccurrence(arr, size, key);

    int result = 0;
    if(first != -1)
        result = last - first + 1;

    cout<<"Total Number of Occurrence of "<<key<<" = "<<result<<endl;

    return 0;
}