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
void solve(string str, string  output, int index, vector<string>& ans) {
    // base case
    if(index >= str.size()) {
        if(output != "")
            ans.push_back(output);
        return ;
    }
    
    // exclude
    solve(str, output, index+1, ans);
    
    // include
    char element = str[index];
    output.push_back(element);
    solve(str, output, index+1, ans);
}

vector<string> subsequences(string str){
	vector<string> ans;
    string output;
    int index = 0;
    solve(str, output, 0, ans);
    
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