// Union of Two Sorted Arrays
// GFG : https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

#include<bits/stdc++.h>

using namespace std;


/*
TC : O(m+n)
SC : O(m+n)
*/
class Solution{
    public:
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(arr1[i] == arr2[j]) {
                if(ans.size() == 0 || ans[ans.size()-1] != arr1[i]) ans.push_back(arr1[i]);
                i++; j++;
            }
            else if(arr1[i] < arr2[j]) {
                if(ans.size() == 0 || ans[ans.size()-1] != arr1[i]) ans.push_back(arr1[i]);
                i++;
            }
            else {
                if(ans.size() == 0 || ans[ans.size()-1] != arr2[j]) ans.push_back(arr2[j]);
                j++;
            }
        }
        while(i < n) {
            if(ans.size() == 0 || ans[ans.size()-1] != arr1[i]) ans.push_back(arr1[i]);
            i++;
        }
        while(j < m) {
            if(ans.size() == 0 || ans[ans.size()-1] != arr2[j]) ans.push_back(arr2[j]);
            j++;
        }
        return ans;
    }
};


int main() {
    

    return 0;
}