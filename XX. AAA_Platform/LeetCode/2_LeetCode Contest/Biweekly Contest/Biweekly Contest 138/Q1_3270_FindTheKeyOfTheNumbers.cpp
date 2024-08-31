// 3270. Find the Key of the Numbers
// LeetCode : https://leetcode.com/problems/find-the-key-of-the-numbers/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int key = 0;
        int cnt = 1;
        while(cnt <= 4 && (num1 || num2 || num3)) {
            key += pow(10,cnt-1) * min(num1%10, min(num2%10, num3%10));
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
            cnt++;
        }
        return key;
    }
};


int main() {
        
    return 0;
}