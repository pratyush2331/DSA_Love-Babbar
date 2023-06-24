// Minimum Bracket Reversal OR Minimum Cost To Make String Valid
// CodeStudio : https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0

#include <bits/stdc++.h> 

int findMinimumCost(string str) {
  if(str.length() & 1) { // for ODD
    return -1;
  }

  stack<char> stack;
  for(int i = 0; i < str.length(); i++) {
    char ch = str[i];
    if(ch == '{') {
      stack.push(ch);
    }
    else {
      if(!stack.empty() && stack.top() == '{') {
        stack.pop();
      }
      else {
        stack.push(ch);
      }
    }
  }

  int a = 0, b = 0;
  while(!stack.empty()) {
    if(stack.top() == '{') {
      a++;
    }
    else {
      b++;
    }
    stack.pop();
  }

  return (a+1)/2 + (b+1)/2;
}