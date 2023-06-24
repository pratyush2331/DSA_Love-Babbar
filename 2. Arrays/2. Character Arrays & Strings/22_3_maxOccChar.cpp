// GFG: Maximum Ocurring Character
/*
sample i/p-1:
output

sample o/p-1:
t
---------------------------------------------------
sample i/p2:
testsample

sample o/p-2:
e
*/



#include<iostream> 
using namespace std;


//Function to find the maximum occurring character in a string.
// TC = O(n), SC = O(1)
char getMaxOccuringChar(string str)
{
    // SC = O(1)
    int arr[26] = {0};

    // storing count of characters in arr
    // TC = O(n)
    for(int i = 0; i < str.length(); i++) {
        arr[tolower(str[i]) - 'a']++;
    }
    
    // find maximum occ character
    // TC = O(1)
    int maxi = arr[0], ans = 0;
    for(int i = 0; i < 26; i++) {
        if(maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
    }

    return ans + 'a';
}


int main() {
    string str;
    cin>>str;

    cout<<getMaxOccuringChar(str)<<endl;

    return 0;
}