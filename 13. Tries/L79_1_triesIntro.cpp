// Trie Implementation

#include<iostream>
using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode* children[26]; // 'A' to 'Z'
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

        // assumption - word will be in CAPS
        int index = word[0] - 'A';
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

        // assumption - word will be in CAPS
        int index = word[0] - 'A';
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

    

    // TC : O(l) - without deleting space
    void removeUtil(TrieNode* root, string word) {
        // base case
        if(word.length() == 0) {
            root->isTerminal = false;
            return;
        }

        // assumption - word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;
        // present
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        // absent
        else {
            return;
        }

        removeUtil(child, word.substr(1));
    }

    void removeWord(string word) {
        removeUtil(root, word);
    }

    // HomeWork : removeWord() - delete spaces which are of no use

};

int main() {
    Trie *t = new Trie();

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    t->insertWord("TIM");

    // cout << "Present or not ? " << t->searchWord("TIME") << endl;
    cout << "Present or not ? " << t->searchWord("TIM") << endl;
    t->removeWord("TIM");
    cout << "Present or not ? " << t->searchWord("TIM") << endl;
    
    return 0;
}