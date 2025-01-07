// 1408. String Matching in an Array
// LeetCode : https://leetcode.com/problems/string-matching-in-an-array/

#include<bits/stdc++.h>
using namespace std;


// method-1 : Trie
class TrieNode {
public:
    char data;
    TrieNode* children[26]; // 'a' to 'z'
    int freq; // Frequency of the node, representing how many words pass through

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        freq = 0;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    // Insert a word and all its suffixes
    void insertWord(string word) {
        for(int i = 0; i < word.length(); i++) {
            TrieNode* current = root;
            for(int j = i; j < word.length(); j++) {
                int index = word[j] - 'a';
                if(current->children[index] == NULL) {
                    current->children[index] = new TrieNode(word[j]);
                }
                current = current->children[index];
                current->freq++; // Increment frequency for every node in the path
            }
        }
    }

    bool isSubstring(string word) {
        TrieNode* current = root;
        for(char ch : word) {
            int index = ch - 'a';
            if(current->children[index] == NULL) {
                return false;
            }
            current = current->children[index];
        }
        return current->freq > 1;
    }
};

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        Trie* t = new Trie();
        for(auto& word : words) {
            t->insertWord(word);
        }

        vector<string> ans;
        for(auto& target : words) {
            if(t->isSubstring(target)) ans.emplace_back(target);
        }
        return ans;
    }
};




// method-0 : Brute Force
/*
TC : O(n^2 . m1 . m2)
SC : O(1)
*/
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i = 0; i < words.size(); i++) { // O(n)
            bool found = 0;
            for(int j = 0; j < words.size(); j++) { // O(n)
                if(i == j) continue;
                for(int k = 0; k < words[j].size(); k++) { // O(m1)
                    int target_idx = 0, idx = k;
                    while(idx < words[j].length() && target_idx < words[i].length() && words[j][idx] == words[i][target_idx]) { // O(m2)
                        target_idx++;
                        idx++;
                    }
                    if(target_idx == words[i].length()) {
                        found = 1;
                        break;
                    }
                }
                if(found) break;
            }
            if(found) ans.emplace_back(words[i]);
        }
        return ans;
    }
};


int main() {
    
    return 0;
}