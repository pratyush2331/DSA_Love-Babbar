// 3174. Clear Digits
// LeetCode : https://leetcode.com/problems/clear-digits/

#include<bits/stdc++.h>
using namespace std;


// method-3 : simple backward traversal with count variable
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        int cnt = 0; // count consecutive digits
        for(int i = s.length()-1; i >= 0; i--) { // TC:O(n)
            if(s[i] >= '0' && s[i] <= '9') {
                cnt++;
            }
            else if(s[i] >= 'a' && s[i] <= 'z' && cnt > 0) {
                cnt--;
            }
            else { // s[i] >= 'a' && s[i] <= 'z' && cnt == 0
                ans += s[i];
            }
        }
        reverse(ans.begin(), ans.end()); // TC:O(n)
        return ans;
    }
};


// method-2 : in-place
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    string clearDigits(string s) {
        // This variable keeps track of the actual length of the resulting
        // string
        int answerLength = 0;

        // Iterate through each character in the input string
        for (int charIndex = 0; charIndex < s.size(); charIndex++) {
            // If the current character is a digit
            if (isdigit(s[charIndex])) {
                // Decrement answerLength to remove the last character from the
                // result
                answerLength = max(answerLength - 1, 0);
            } else {
                // Place the character in the "answer" portion of the string
                s[answerLength++] = s[charIndex];
            }
        }

        // Resize the string to match the actual length of the answer
        s.resize(answerLength);

        return s;
    }
};


// method-1 : stack like
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    string clearDigits(string s) {
        string answer;

        // Iterate over each character in the input string
        for (int charIndex = 0; charIndex < s.size(); charIndex++) {
            // If the current character is a digit
            if (isdigit(s[charIndex]) && !answer.empty()) {
                // If the answer string is not empty, remove the last character
                answer.pop_back();
            } else {
                // If the character is not a digit, add it to the answer string
                answer += s[charIndex];
            }
        }

        return answer;
    }
};


// method-0 : Brute Force (2 loops)
/*
TC : O(n^2)
SC : O(1)
*/
class Solution {
public:
    string clearDigits(string s) {
        int charIndex = 0;

        // Until we reach the end of the string
        while (charIndex < s.size()) {
            if (isdigit(s[charIndex])) {
                // Remove the digit from the string
                s.erase(charIndex, 1);
                // If there is a character to the left of the digit, remove it
                if (charIndex > 0) {
                    s.erase(charIndex - 1, 1);
                    // Adjust the index to account for the removed character
                    charIndex--;
                }
            } else {
                // Move to the next character if it's not a digit
                charIndex++;
            }
        }
        return s;
    }
};


int main() {
    
    return 0;
}