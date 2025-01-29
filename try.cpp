// Array / Vector
// searching, sorting
// searching --> linear search, binary search
// sorting --> insertions sort, selection sort, bubble sort, quick sort, merge sort,...

#include<bits/stdc++.h>
using namespace std;

int find(vector<int>& arr, int target) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == target) return i;
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 4, -1, 0, 4, 10, 11};

    // linear search
    int val = 10;
    int found = find(arr, val);
    cout << val << " found at index : " << found << endl;
    
    return 0;
}