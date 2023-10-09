// 374. Guess Number Higher or Lower
// leetCode : https://leetcode.com/problems/guess-number-higher-or-lower/

#include<iostream>
using namespace std;


/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
    // Binary Search
    public:
    int guessNumber(int n) {
        int s = 1, e = n;
        int mid = s + (e-s)/2;
        while(s <= e) {
            int pick = guess(mid);
            if(pick == 0)
                return mid;
            if(pick == -1) {
                e = mid - 1;
            }
            else { // pick = +1
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }
};


int main() {
    
    return 0;
}