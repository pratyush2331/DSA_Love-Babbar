// Reverse words in a given string
// GFG : https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

#include<iostream>
using namespace std;


class Solution {
    public:
    string reverseWords(string S) {
        // code here 
        string ans = "";
        
        string temp = "";
        for(int i = S.length()-1; i >= 0; i--) {
            if(S[i] == '.') {
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans.push_back('.');
                temp = "";
            }
            else {
                temp += S[i];
            }
        }
        
        reverse(temp.begin(), temp.end());
        ans += temp;
        
        return ans;
    }
};


int main() {
    
    return 0;
}