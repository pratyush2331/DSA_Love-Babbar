// Add Binary
// LeetCode : https://leetcode.com/problems/add-binary/

#include<iostream>
using namespace std;


class Solution {
    public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0, sum = 0;
        while(i < a.size() && i < b.size()) {
            int b0 = (a[i] == '1') ? 1 : 0;
            int b1 = (b[i] == '1') ? 1 : 0;
            sum = b0 + b1 + carry;
            carry = sum / 2;
            sum = sum % 2;
            ans += ((sum == 1) ? '1' : '0');
            i++;
        }
        while(i < a.size()) {
            int b0 = (a[i] == '1') ? 1 : 0;
            sum = b0 + carry;
            carry = sum / 2;
            sum = sum % 2;
            ans += ((sum == 1) ? '1' : '0');
            i++;
        }
        while(i < b.size()) {
            int b1 = (b[i] == '1') ? 1 : 0;
            sum = b1 + carry;
            carry = sum / 2;
            sum = sum % 2;
            ans += ((sum == 1) ? '1' : '0');
            i++;
        }
        if(carry == 1) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    
    return 0;
}