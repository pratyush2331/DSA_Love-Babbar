// Leaders in array
// GFG : https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

/*
Example 1:
6
3 12 34 2 0 -1

34 2 0 -1
-------------------------------------------------------------------------------------

Example 2:
5
13 17 5 4 6

17 6
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> ans;
        
        int maxi = INT_MIN;
        for(int i = n-1; i >= 0; i--) {
            if(a[i] >= maxi) {
                ans.push_back(a[i]);
                maxi = max(maxi, a[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

    return 0;
}
