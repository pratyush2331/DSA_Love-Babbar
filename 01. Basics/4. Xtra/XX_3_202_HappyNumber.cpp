// 202. Happy Number
// LeetCode : https://leetcode.com/problems/happy-number/description/


// method-1 : using Floyd's Cycle Detection Algorithm
/*
TC : O(logn)
SC : O(logn); can be optimized with loop
*/
#include <cmath>
class Solution {
    int sum1(int n) {
        int sum = 0;
        while(n) {
            sum += pow(n%10, 2);
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = sum1(slow);
            fast = sum1(sum1(fast));
        } while(slow != fast);
        return slow == 1;
    }
};


// method-0 : 4 is starting point of every cycle
/*
TC : O(logn)
SC : O(logn); can be optimized with loop
*/
class Solution {
    int sum1(int n) {
        int sum = 0;
        while(n) {
            sum += pow(n%10, 2);
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = sum1(slow);
            fast = sum1(sum1(fast));
        } while(slow != fast);
        return slow == 1;
    }
};