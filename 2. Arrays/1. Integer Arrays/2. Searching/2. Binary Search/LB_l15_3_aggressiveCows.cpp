// Aggressive Cows Problem
// CodeStudio : https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559

/* ----------------------------------------------PROBLEM STATEMENT----------------------------------------------
Given an array of length ‘N’, where each element denotes the position of a stall. Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive. To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. Return the largest minimum distance.
Given an array of length ‘N’, where each element denotes the position of a stall. Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive. To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. Return the largest minimum distance.
--------------------------------------------------------------------------------------------------------------- */

/*
    sample i/p-1:   3 2
                    1 2 3
    sample o/p-1:   2

    sample i/p-2:   5 2
                    4 2 1 3 6
    sample o/p-2:   5

    sample i/p-3:   6 4
                    0 3 4 7 10 9
    sample o/p-3:   3

    sample i/p-4:   6 3
                    0 4 3 7 10 9
    sample o/p-4:   4
*/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> stalls, int n, int k, int mid) {
    int cowCount = 1;
    int lastPos = stalls[0];
    
    for(int i = 0; i < n; i++) {
        if(stalls[i] - lastPos >= mid) {
            cowCount++;
            if(cowCount == k) return true;
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    
    int s = 0;
    int e = stalls[n-1];
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e) {
        if(isPossible(stalls, n, k, mid)) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {
    vector<int> stalls;
    int n, k;
    cin>>n>>k;

    for(int i = 0; i < n; i++) {
        int data;
        cin>>data;
        stalls.push_back(data);
    }

    cout<<aggressiveCows(stalls, k)<<endl;
    
    return 0;
}