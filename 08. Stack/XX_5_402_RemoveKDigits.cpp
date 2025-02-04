x// 402. Remove K Digits
// LeetCode : https://leetcode.com/problems/remove-k-digits/

#include<bits/stdc++.h>
using namespace std;


// using stack/dequeue
/*
TC : O(n)
SC : O(n)
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        // edge case
        if(k == num.size()) return "0";

        // use monotonic stack logic...
        stack<char> st;
        for(char& ele : num) {
            while(!st.empty() && k > 0 && (st.top() - '0') > (ele - '0')) {
                st.pop();
                k--;
            }
            st.push(ele);
        }

        // remove from last, if still k > 0 && all are in increasing order in stack
        while(k > 0) {
            st.pop();
            k--;
        }

        // make 'ans' string from stack
        string ans;;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // remove '0' from the end of 'ans' string
        while(ans.size() && ans.back() == '0') {
            ans.pop_back();
        }

        // rverese the 'ans' string
        reverse(ans.begin(), ans.end());

        // edge case
        if(ans == "") return "0";
        else return ans;
    }
};


int main() {
    
    return 0;
}