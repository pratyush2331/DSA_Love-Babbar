// 150. Evaluate Reverse Polish Notation
// LeetCode : https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include<iostream>
using namespace std;


// using switch-case
class Solution {
    public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                s.push(stoi(tokens[i]));
                // s.push(tokens[i][0]); // this would work when number is from 0 to 9
            }
            else {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                
                char op = tokens[i][0]; // imp
                switch(op) {
                    case '+':
                        s.push(b + a);
                        break;

                    case '-':
                        s.push(b - a);
                        break;

                    case '*':
                        s.push(b * a);
                        break;

                    case '/':
                        s.push(b / a);
                        break;
                }
            }
        }
        return s.top();
    }
};

// using if-else
/*
class Solution {
    public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                s.push(stoi(tokens[i]));
            }
            else if(tokens[i] == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                s.push(b + a);
            }
            else if(tokens[i] == "-") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                s.push(b - a);
            }
            else if(tokens[i] == "*") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                s.push(b * a);
            }
            else if(tokens[i] == "/") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                s.push(b / a);
            }
        }
        return s.top();
    }
};
*/


int main() {
    
    return 0;
}