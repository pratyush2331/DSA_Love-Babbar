// CodeStudio : Replace Spaces
// You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.

/*
Sample Input 1:
2           <------------      no. of test case
Coding Ninjas Is A Coding Platform
Hello World

Sample Output 1:
Coding@40Ninjas@40Is@40A@40Coding@40Platform
Hello@40World
--------------------------------------------------------------
Sample Input 2:
3           <------------      no. of test case
Hello
I love coding
Coding Ninjas India

Sample Output 2:
Hello
I@40love@40coding
Coding@40Ninjas@40India    
*/

#include<bits/stdc++.h>

using namespace std;


// Method-1
// TC: O(n), SC: O(n)
string replaceSpaces(string &str){
    string ans;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') {
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
        }
        else {
            ans.push_back(str[i]);
        }
    }
    
    return ans;
}

// Method-2
// TC: O(n), SC: O(1)
// string replaceSpaces(string &str){
//     for(int i = 0; i < str.length(); i++) {
//             if(str[i] == ' ') {
//                 str.erase(i, 1);
//                 str.insert(i, "@40");
//             }
//         }
//     return str;
// }

// ------------------OR---------------------

// Method-3
// TC: O(n), SC: O(1)
// string replaceSpaces(string &str){
//     for(int i = 0; i < str.length(); i++) {
//             if(str[i] == ' ') {
//                 str.replace(i , 1, "@40");
//             }
//         }
//     return str;
// }


int main() {
    string str;

    getline(cin, str);

    // cout<<str<<endl; 

    cout<<replaceSpaces(str)<<endl;

    return 0;
}