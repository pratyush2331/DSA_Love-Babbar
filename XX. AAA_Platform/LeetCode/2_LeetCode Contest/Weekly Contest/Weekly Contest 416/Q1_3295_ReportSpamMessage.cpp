// 3295. Report Spam Message
// LeetCode : https://leetcode.com/problems/report-spam-message/

#include<bits/stdc++.h>
using namespace std;


// method-1 : using map


// method-0 : using Trie
class TrieNode {
    public:
    char data;
    TrieNode* children[26]; // 'a' to 'z'
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        // base case
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // assumption - word will be in SMALL
        int index = word[0] - 'a';
        TrieNode* child;
        // present
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        // absent
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    // TC : O(l)
    void insertWord(string word) {
        insertUtil(root, word);
    }



    bool searchUtil(TrieNode* root, string word) {
        // base case
        if(word.length() == 0) {
            return root->isTerminal;
        }

        // assumption - word will be in SMALL
        int index = word[0] - 'a';
        TrieNode* child;
        // present
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        // absent
        else {
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    // TC : O(l)
    bool searchWord(string word) {
        return searchUtil(root, word);
    }
};

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        Trie* t = new Trie();
        for(auto word : bannedWords) {
            t->insertWord(word);
        }

        int cnt = 0;
        for(auto word : message) {
            if(t->searchWord(word)) cnt++;
        }
        return (cnt >= 2) ? 1 : 0;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}