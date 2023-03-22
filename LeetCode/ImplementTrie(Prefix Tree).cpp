// Problem Link: https://leetcode.com/problems/implement-trie-prefix-tree/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Trie {
public:
    Trie* children[26] = {};
    bool isWord = false;
    
    void insert(string word) {
        Trie* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->children[c] == nullptr)
                cur->children[c] = new Trie();
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->children[c] == nullptr) return false;
            cur = cur->children[c];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for (char c : prefix) {
            c -= 'a';
            if (cur->children[c] == nullptr) return false;
            cur = cur->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */