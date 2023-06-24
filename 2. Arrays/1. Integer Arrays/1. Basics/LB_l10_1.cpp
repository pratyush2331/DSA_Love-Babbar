// SwapAlternate(int arr[], int size);

/*
Input_1:         1 2 3 4 5 6 7 8 9    
Output_1:        2 1 4 3 6 5 8 7 9    

Input_2:         1 2 3 4 5 6 7 8 9 10 
Output_2:        2 1 4 3 6 5 8 7 10 9 
*/

#include<iostream>
using namespace std;

void swapAlternate(int arr[], int size)
{
    int index = 0;
    while(index+1 < size){
        swap(arr[index], arr[index+1]);
        index += 2;
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int odd[9] = {1,2,3,4,5,6,7,8,9};
    int even[10] = {1,2,3,4,5,6,7,8,9,10};

    printArray(odd, 9);
    swapAlternate(odd, 9);
    printArray(odd, 9);

    cout<<endl;

    printArray(even, 10);
    swapAlternate(even, 10);
    printArray(even, 10);
    
    return 0;
}