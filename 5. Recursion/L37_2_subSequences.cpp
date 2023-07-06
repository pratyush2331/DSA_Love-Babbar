// CodeStudio : Sub Sequences of String

/*
Sample Input 1:
1 
abc
Sample Output 1:
a ab abc ac b bc c

Sample Input 2:
1
bbb
Sample Output 2:
b b b bb bb bb bbb
*/

#include<iostream>
#include<vector>
using namespace std;

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
    int index = 0; // to decide which index to take & not-take
    solve(str, index, output, ans);
	
    return ans;
}


int main() {
    string str;
    cin >> str;

    vector<string> ans = subsequences(str);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}