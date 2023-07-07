#include<bits/stdc++.h>
using namespace std;

// Method1 : Bit manipulation
/*
TC : O(2^n)
SC : O(2^n)
*/
// /*
vector<string> subsequences(string str){
	vector<string> ans;

    int n = str.length();
    for(int num = 0; num < (1<<n); num++) {
        string sub = "";
        for(int i = 0; i < n; i++) {
            if(num & (1<<i))
                sub += str[i];
        }

        // store in ans, if output is not an empty string
        if(sub != "")
            ans.push_back(sub);
    }

    return ans;	
}
// */



// Method0 : Recursion
/*
TC : O(2^n)
SC : O(2^n)
*/
/*
void solve(string str, int index, string output, vector<string>& ans) {
    // base case
    if(index >= str.length()) {
        if(output != "") { // store in ans, if output is not an empty string
            ans.push_back(output);
        }
        return;
    }
    
    // exclude
    solve(str, index+1, output, ans);
    
    // include
    char element = str[index];
    output.push_back(element);
    solve(str, index+1, output, ans);
}

vector<string> subsequences(string str){
	vector<string> ans; // to store all subsequences
    string output; // to store 1 subsequence at a time

    solve(str, 0, output, ans);
    
    return ans;
}
*/


int main() {
    string str;
    cin >> str;

    vector<string> ans = subsequences(str);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}