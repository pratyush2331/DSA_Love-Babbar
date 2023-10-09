// Rverse the array after mth index
// Coding Ninjas : https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298

// Given an array/list 'ARR' of integers and a position ‘M’. You have to reverse the array after that position.

/*
sample i/p: 
2
6 3
1 2 3 4 5 6
5 2
10 9 8 7 6

sample O/p: 
1 2 3 4 6 5
10 9 8 6 7
*/

#include<iostream>
#include<vector>

using namespace std;

void reverseArray(vector<int> &arr, int m) {
    int s = m+1, e = arr.size()-1;

    while(s <= e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void printArray(vector<int> arr, int n) {
    for(auto i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        vector<int> arr;

        int n, m;
        cin>>n>>m;
        for(int i = 0; i < n; i++) {
            int data;
            cin>>data;
            arr.push_back(data);
        }

        reverseArray(arr, m);

        printArray(arr, n);
    }

    return 0;
}