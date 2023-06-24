// Painter's Partition Problem
// CodeStudio : https://www.codingninjas.com/codestudio/problems/painter-s-partition-problem_1089557
// similar to Book Allocation Problem

/*---------------------------------------------PROBLEM STATEMENT---------------------------------------------
Calculate and return the minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of the board.
 NOTE: 
    1. 2 painters cannot share a board to paint. That is to say, a board cannot be painted partially by one painter, and partially by another.
    2. A painter will only paint contiguous boards. This means a configuration where painter 1 paints boards 1 and 3 but not 2 is invalid.
-------------------------------------------------------------------------------------------------------------*/

/*
    sample i/p-1:   4 2
                    5 5 5 5
    sample o/p-1:   10

    sample i/p-2:   4 2
                    10 20 30 40
    sample o/p-2:   60

    sample i/p-3:   2 2
                    48 90
    sample o/p-3:   90

    sample i/p-4:   4 2
                    1 2 3 4
    sample o/p-4:   6
*/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &boards, int n, int k, int mid) {
    int painterCount = 1;
    int area = 0;

    for(int i = 0; i < n; i++) {
        if(area + boards[i] <= mid) {
            area += boards[i];
        }
        else {
            painterCount++;
            if(painterCount > k || boards[i] > mid) return false;
            area = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();

    int s = 0;

    int sum = 0;
    for(int i  = 0; i < n; i++) {
        sum += boards[i];
    }

    int e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e) {
        if(isPossible(boards, n, k, mid)) {
            ans = mid;
            e = mid-1;
        }
        else {
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {
    vector<int> boards;
    int n, k;
    cin>>n>>k;

    for(int i = 0; i < n; i++) {
        int data;
        cin>>data;
        boards.push_back(data);
    }

    cout<<findLargestMinDistance(boards, k)<<endl;
    return 0;
}