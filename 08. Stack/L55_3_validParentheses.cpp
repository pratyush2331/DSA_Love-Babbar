// 20. Valid Parentheses
// LeetCode : https://leetcode.com/problems/valid-parentheses/

bool matches(char ch1, char ch2) {
    if(ch1 == '[' && ch2 == ']') return true;
    if(ch1 == '{' && ch2 == '}') return true;
    if(ch1 == '(' && ch2 == ')') return true;
    return false;
}

bool isValid(string s) {
    int len = s.length();
    stack<char> st;
    for(int i = 0; i < len; i++) {
        char ch = s[i];
        if(ch == '[' || ch == '{' || ch == '(' || ch == ')' || ch == '}' || ch == ']') { // for generalizing
            if(ch == '[' || ch == '{' || ch == '(') { // for opening braces
                st.push(ch);
            }
            else { // for closing braces
                if(!st.empty()) {
                    char top = st.top();
                    if(matches(top, ch)) {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }
    }

    if(st.empty()) {
        return true;
    }
    else {
        return false;
    }
}