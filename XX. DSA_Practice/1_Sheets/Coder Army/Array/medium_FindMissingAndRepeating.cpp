// Find Missing And Repeating
// GFG : https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1


/*
constraint : do it in TC: O(n) and SC: O(1).
*/


#include<bits/stdc++.h>

using namespace std;


// method-2 : using xor
/*
TC : O(3n) = O(n)
SC : O(1)
*/
/*
class Solution{
    public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int x = -1, y = -1;
        
        int xorSum = 0;
        for(int i = 0; i < n; i++) {
            xorSum ^= (i+1) ^ (arr[i]);
        }
        
        int righMostSetBit = xorSum & -xorSum;
        
        int grp0 = 0, grp1 = 0;
        for(int i = 0; i < n; i++) {
            // grp1
            if(arr[i] & righMostSetBit) grp0 ^= arr[i];
            // grp0
            else grp1 ^= arr[i];
            // grp1
            if((i+1) & righMostSetBit) grp0 ^= (i+1);
            // grp0
            else grp1 ^= (i+1);
        }
        
        for(int i = 0; i < n; i++) {
            if(grp0 == arr[i]) {
                x = grp0;
                y = grp1;
                break;
            }
            if(grp1 == arr[i]) {
                x = grp1;
                y = grp0;
                break;
            }
        }
        
        return {x,y}; 
    }
};
*/



// method-1 : using visited/non-visited
/*
TC : O(2n) = O(n)
SC : O(1)
*/
class Solution{
    public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int> ans(2);
        
        for (int i = 0; i < n; i++) {
            if (arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            else
                ans[0] = abs(arr[i]);
        }
        
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) ans[1] = i + 1;
        }
        
        return ans;
    }
};



// method-0 : using simple maths
/*
TC : O(n) --> in one traverse
SC : O(1)
*/
/*
class Solution{
    public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int x = -1, y = -1;
        
        long long sn = ((long long)n * (long long)(n+1)) / 2;
        long long s2n = ((long long)n * (long long)(n+1) * (2 * (long long)n+1)) / 6;
        long long s = 0, s2 = 0;
        for(int i = 0; i < n; i++) {
            s += arr[i];
            s2 += (long long)arr[i] * (long long)arr[i];
        }
        
        // solve equation
        long long xyDiff = (s - sn);
        long long xySum = (s2 - s2n);
        xySum = xySum / xyDiff;
        
        // update x & y
        x = (xySum + xyDiff) / 2;
        y = xySum - x;
        
        return {x,y}; 
    }
};
*/


int main() {
    

    return 0;
}