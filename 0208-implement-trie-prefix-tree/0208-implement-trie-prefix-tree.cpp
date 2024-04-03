class TrieNode{
    public:
    TrieNode* alpha[26];
    bool valid = false;
    
    TrieNode(){
        for(int i = 0; i < 26; i++){
            alpha[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        
        for(auto c: word){
            int pos = c - 'a';
            if(!curr->alpha[pos]){
                curr->alpha[pos] = new TrieNode();
            }
            
            curr = curr->alpha[pos];
        }
        
        curr->valid = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        
        for(auto c: word){
            int pos = c - 'a';
            if(!curr->alpha[pos]){
                return false;
            }
            
            curr = curr->alpha[pos];
        }
        
        return curr->valid;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        
        for(auto c: prefix){
            int pos = c - 'a';
            if(!curr->alpha[pos]){
                return false;
            }
            
            curr = curr->alpha[pos];
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