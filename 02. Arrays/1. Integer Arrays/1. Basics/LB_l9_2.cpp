// input & output, min & max, sum, linear search in Array

#include<iostream>
using namespace std;

// input array
template <class T>
void input(T arr[], int size) {
    cout<<"Enter Array: ";
    for(int i = 0; i < size; i++) {
        cin>>arr[i];
    }
    cout<<endl;
}

// print array
template <class T>
void print(T arr[], int size) {
    cout<<"Printing Array: "<<endl;
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// finding max value
void getMax(int arr[], int size) {
    int maxi = INT_MIN;
    for(int i = 0; i <size; i++) {
        // maxi = max(maxi, arr[i]);
        if(arr[i] > maxi)
            maxi = arr[i];
    }
    cout<<"Maximum value = "<<maxi<<endl;
}

// finding min value
void getMin(int arr[], int size) {
    int mini = INT_MAX;
    for(int i = 0; i < size; i++) {
        // mini = min(mini, arr[i]);
        if(arr[i] < mini)
            mini = arr[i];
    }
    cout<<"Minimum Value = "<<mini<<endl;
}

// finding sum
void sum(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout<<"Sum = "<<sum<<endl;
}

// Linear Search
bool search(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key)
            return 1;
    }
    return 0;
}

int main(){
    int arr[100];

    // taking size
    int size;
    cout<<"Enter size: ";
    cin>>size;

    input(arr, size);

    print(arr, size);

    // for integer only
    getMax(arr, size);

    // for integer only
    getMin(arr, size);

    // printing sum
    sum(arr, size);

    // Linear Search
    cout<<"Enter key: ";
    int key;
    cin>>key;
    bool found = search(arr, size, key);
    if(found)
        cout<<"Key is present"<<endl;
    else 
        cout<<"Key is absent"<<endl;

    return 0;
}