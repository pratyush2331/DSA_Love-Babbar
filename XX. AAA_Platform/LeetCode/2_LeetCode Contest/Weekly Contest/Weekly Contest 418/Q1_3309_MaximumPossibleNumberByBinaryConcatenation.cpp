// 3309. Maximum Possible Number by Binary Concatenation
// LeetCode : https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation

#include<bits/stdc++.h>
using namespace std;


/*
TC : O(n.logn)
SC : O(n)
*/
class Solution {
public:
    int maxGoodNumber(vector<int>& nums){
        // step 1: store corresponding binary in string format
        vector<string> binReprs;
        for(int i = 0; i < nums.size(); i++){
            string bin = "";
            int val = nums[i];
            while(val){
                bin = to_string(val&1) + bin;
                val = val>>1;
            }
            binReprs.push_back(bin);
        }

        // IMP
        // step 2: sort acc. to the question
        sort(binReprs.begin(), binReprs.end(), [](const string& x, const string& y){
            return x + y > y + x;
        });

        // step 3: concatenate the strings
        string concatenatedBin = "";
        for(const string& binary : binReprs){
            // cout << binary << " ";
            concatenatedBin += binary;
        }

        // step 4: form the corresponding integer using binary-concatenated-string
        int finalNumber = 0;
        for(char bit : concatenatedBin){
            finalNumber = (finalNumber << 1) + (bit - '0');
        }

        return finalNumber;
    }
};


int main() {
    
    return 0;
}