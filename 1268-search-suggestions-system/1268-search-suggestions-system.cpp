class TrieNode{
    public:
    TrieNode* alpha[26];
    bool isWord = false;
    
    TrieNode(){
        for(int i = 0; i < 26; i++){
            alpha[i] = nullptr;
        }
    }
};

class Solution {
public:
    TrieNode* root;
    vector<string> mid;
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode();
        
        for(string product: products){
            TrieNode* curr = root;
            
            for(char c: product){
                if(!curr->alpha[c-'a']){
                    curr->alpha[c-'a'] = new TrieNode();
                }
                
                curr = curr->alpha[c-'a'];
            }    
            
            curr->isWord = true;
        }
        
        vector<vector<string>> ans;
        
        for(int i = 1; i <= searchWord.length(); i++){
            string str = searchWord.substr(0, i);
            
            TrieNode* curr = root;
            bool noAns = false;
            
            for(int j = 0; j < i; j++){
                if(!curr->alpha[str[j]-'a']){
                    noAns = true;   
                    break;
                }
                
                curr = curr->alpha[str[j]-'a'];
            }
            
            if(noAns){
                for(int j = i; j <= searchWord.length(); j++){
                    ans.push_back({});
                }
                
                break;
            }
            
            vector<string> cand = dfs(curr);
            for(int j = 0; j < cand.size(); j++){
                 cand[j] = str + cand[j];
            }
            ans.push_back(cand);
        }
        
        return ans;
    }
    
    vector<string> dfs(TrieNode* curr){
        vector<string> res;
        
        if(curr->isWord){
            res.push_back("");
        }
        
        for(int i = 0; i < 26; i++){
            if(curr->alpha[i]){
                vector<string> x = dfs(curr->alpha[i]);
                char c = (i + 'a');
                
                for(int j = 0; j < x.size(); j++){
                    x[j] = c + x[j];
                    res.push_back(x[j]);
                    
                    if(res.size() == 3)
                        return res;
                }
            }
        }
        
        return res;
    }
    
    
};