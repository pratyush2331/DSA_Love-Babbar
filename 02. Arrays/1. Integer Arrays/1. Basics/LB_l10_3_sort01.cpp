// sort01(int arr[], int size);

#include<iostream>
using namespace std;

// Method-1: 2-pointer approach
// TC : O(n)
void sort01(int arr[], int size) {
    int i=0, j=size-1;
    while(i < j) {
        if(arr[i] == 0) i++;
        else if(arr[j] == 1) j--;
        else swap(arr[i++], arr[j--]);
    }
}

// Method-2: counting sort
// TC : O(n)
/*
void sort01(int arr[], int size)
{
    int c0=0, c1=0;
    for(int i=0; i<size; i++)
    {
        if(arr[i] == 0)
        {
            c0++;
        }
        else
        {
            c1++;
        }
    }
    int i=0;
    while(c0)
    {
        arr[i] = 0;
        i++;
        c0--;
    }
    while(c1)
    {
        arr[i] = 1;
        i++;
        c1--;
    }
}
*/


void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {1,0,0,1,0,1,0,0,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort01(arr, n);
    printArray(arr, n);

    return 0;
}