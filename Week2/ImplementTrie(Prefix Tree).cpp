//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isLast = false;
        for (int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
    bool isLast;
    TrieNode* child[26];
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
     
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for(int i= 0 ;i<word.length();i++){
            int index = word[i]-'a';
            if(curr->child[index]==NULL){
                curr->child[index]  = new TrieNode();
            }
            curr = curr->child[index];
        }
        curr->isLast  = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++){
            int index = word[i]-'a';
            if(curr->child[index]==NULL){
                return false;
            }
            curr = curr->child[index];
        }
        return curr->isLast;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i= 0;i<prefix.length();i++){
            int index= prefix[i]-'a';
            if(curr->child[index]==NULL)
                return false;
            curr = curr->child[index];
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
