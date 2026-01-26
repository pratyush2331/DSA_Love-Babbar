// 875. Koko Eating Bananas
// LeetCOde : https://leetcode.com/problems/koko-eating-bananas/

#include<bits/stdc++.h>
using namespace std;

/*
TC : O(N . log M) , M = max element in piles
SC : O(1)
*/
class Solution {
    bool isPossible(int mid, vector<int>& piles, int h) {
        int hours = 0;
        for(int& ele : piles) {
            hours += ceil((double)ele / mid);
            if(hours > h) return false;
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0, maxi = INT_MIN;
        for(int& ele : piles) {
            maxi = max(maxi, (long long)ele);
            sum += ele;
        }

        // Binar Search logic
        long long s = ceil((double)sum / h), e = maxi;
        long long mid = s + (e - s) / 2; // mid = speed
        long long ans = -1;
        while(s <= e) {
            if(isPossible(mid, piles, h)) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }

        return ans;
    }
};


int main() {
    
    return 0;
}