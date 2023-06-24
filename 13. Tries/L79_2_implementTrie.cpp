// 208. Implement Trie (Prefix Tree)
// LeetCode : https://leetcode.com/problems/implement-trie-prefix-tree/

#include<iostream>
using namespace std;

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
        // write your code here
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word) {
        // base case
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // assumption - word will be in CAPS
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

    void insert(string word) {
        // write your code here
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        // base case
        if(word.length() == 0) {
            return root->isTerminal;
        }

        // assumption - word will be in CAPS
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
    
    bool search(string word) {
        // write your code here
        return searchUtil(root, word);
    }

    bool prefixUtil(TrieNode* root, string word) {
        // base case
        if(word.length() == 0) {
            return true;
        }

        // assumption - word will be in CAPS
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
        return prefixUtil(child, word.substr(1));
    }
    
    bool startsWith(string prefix) {
        // write your code here
        return prefixUtil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    
    return 0;
}