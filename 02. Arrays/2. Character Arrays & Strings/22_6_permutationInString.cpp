// LeetCode-567: Permutation In String

/*
Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

--------------------------------------------------------------------------

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/



// Overall TC: O(m + n), SC: O(1)
#include<iostream>
using namespace std;

bool checkEqual(int count1[], int count2[]) {
    for(int i = 0; i < 26; i++) {
        if(count1[i] != count2[i]) {
            return 0;
        }
    }
    
    return 1;
}

bool checkInclusion(string s1, string s2) {
    
    // Character array me s1 ka count store krne k liye
    int count1[26] = {0};
    for(int i = 0; i < s1.length(); i++) {
            int index = s1[i] - 'a';
            count1[index]++;
    }

    // Calculating Window Size
    int windowSize = s1.length();
    
    // traverse s2-string in window of size s1.length & compare

    // 1st window k liye
    int count2[26] = {0};
    int i = 0;
    while(i < windowSize && i < s2.length()) {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    
    // Equal h kya ?
    if( checkEqual(count1, count2) ) {
        return 1;
    }
    
    // Baaki k window k liye
    while(i < s2.length()) {

        // New Character ka count ++ kr rhe h
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;
        
        // Old Character ka count -- kr rhe h
        char oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--;
        
        // Equal h kya ?
        if( checkEqual(count1, count2) ) {
            return 1;
        }
        
        i++;

    }
    
    return 0;

}

int main() {
    string s1, s2;
    cin>>s1>>s2;

    cout<<checkInclusion(s1, s2)<<endl;

    return 0;
}