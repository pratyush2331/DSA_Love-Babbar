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

void solve(string str, string output, int index, vector<string>& ans) {
    // base case
    if(index >= str.length()) {
        if(output != "") {
            ans.push_back(output);
        }
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
    solve(str, output, index, ans);
	
    return ans;
}


int main() {
    string str;
    cin >> str;

    vector<string> ans = subsequences(str);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    
    return 0;
}