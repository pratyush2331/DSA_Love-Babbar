// Three way partitioning
// GFG : https://www.geeksforgeeks.org/problems/three-way-partitioning/1

#include<bits/stdc++.h>

using namespace std;


// Approach : similart to sort 012 problem
/*
TC : O(n)
SC : O(1)
*/
class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b) {
        int n = arr.size();
        int i = 0, j = 0, k = n-1;
        while(j <= k) {
            if(arr[j] < a) swap(arr[i++], arr[j++]);
            else if(arr[j] >= a && arr[j] <= b) j++;
            else if(arr[j] > b) swap(arr[j], arr[k--]);
        }
        
        // for(auto ele : arr) cout << ele << " ";
        // cout << "\n";
    }
};


int main() {
    

    return 0;
}