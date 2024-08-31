// 3265. Count Almost Equal Pairs I
// LeetCode : https://leetcode.com/problems/count-almost-equal-pairs-i/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                string num1 = to_string(nums[i]);
                string num2 = to_string(nums[j]);

                // special case for leading zeros
                while(num1.size() < num2.size()) num1 = "0" + num1;
                while(num2.size() < num1.size()) num2 = "0" + num2;

                vector<int> mismatch;
                for (int k = 0; k < num1.size(); k++) {
                    if (num1[k] != num2[k]) {
                        mismatch.push_back(k);
                    }
                }

                if (mismatch.size() == 2) {
                    swap(num1[mismatch[0]], num1[mismatch[1]]);
                    if (num1 == num2) {
                        ans++;
                    }
                }
                else if (mismatch.size() == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};


int main() {
        
    return 0;
}