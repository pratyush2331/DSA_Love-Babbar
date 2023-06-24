// Beautiful Triplets
// Hackerrank : https://www.hackerrank.com/challenges/beautiful-triplets/problem

/*
Given a sequence of integers , a triplet  is beautiful if:
    1. i < j < k
    2. a[j] - a[i] = a[k] - a[j] = d

Given an increasing sequenc of integers and the value of , count the number of beautiful triplets in the sequence.
*/

/*
    sample i/p: 7 3 
                1 2 4 5 7 8 10
    sample o/p: 3
*/

// using Binary Search
#include<bits/stdc++.h>
using namespace std;

bool isPresent(vector<int> arr, int n, int target) { // Binary Search
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    while(s <= e) {
        if(target == arr[mid]) return true;
        if(target > arr[mid]) s = mid+1;
        else e = mid-1;
        mid = s + (e-s)/2;
    }
    return false;
}

int beautifulTriplets(int d, vector<int> arr) {
    int n = arr.size();
    
    int count = 0;
    for(int i = 0; i < n; i++) {
        int x = arr[i];
        int y = x + d;
        int z = x + 2*d;
        if(isPresent(arr, n, y) && isPresent(arr, n, z)) {
            count++;
        }
    }
    return count;
}

// WITHOUT BINARY SEARCH
/*
int beautifulTriplets(int d, vector<int> arr) {
    int n = arr.size();
    int count = 0;
    for(int i = 0; i < n-2; i++) {
        for(int j = i + 1; j < n-1; j++) {
            if(arr[j]-arr[i] != d) continue;
            for(int k = j + 1; k < n; k++) {
                if(arr[k]-arr[j] == d) count++;
            }
        }
    }
    return count;
}
*/

int main() {
    int n, d;
    cin>>n>>d;

    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int data;
        cin>>data;
        arr.push_back(data);
    }

    cout<<beautifulTriplets(d, arr)<<endl;

    return 0;
}