// Coding Ninjas : Check If Binary Representation of a Number is Palindrome
/*
sample input : 
2    
7
10
sample output : 
true
false
*/

#include<iostream>
#include<vector>
using namespace std;

// with recursion
bool solve(vector<bool> ans, int s) {
    // base case - 1
    if(s > ans.size()-1-s) {
        return 1;
    }
    // base case - 2
    if(ans[s] != ans[ans.size()-1-s]) {
        return 0;
    }
    s++;
    // recurrence relation
    return solve(ans, s);
}

bool checkPalindrome(long long N)
{
    vector<bool> ans;
    while(N) {
        bool bit = N&1;
        ans.push_back(bit);
        N = N >> 1;
    }
    return solve(ans, 0);
}



// without recursion
/*
bool checkPalindrome(long long N)
{
    vector<bool> ans;
	while(N) {
        bool bit = N&1;
        ans.push_back(bit);
        N = N >> 1;
    }
    int s = 0, e = ans.size()-1;
    while(s < e) {
        if(ans[s++] != ans[e--]) {
            return 0;
        }
    }
    return 1;
}
*/


int main() {
    long long N;
    cin >> N;

    if(checkPalindrome(N)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    
    return 0;
}
