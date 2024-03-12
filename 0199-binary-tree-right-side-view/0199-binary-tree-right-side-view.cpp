/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        
        vector<int> res;
        queue<TreeNode*> currLevel, nextLevel;
        nextLevel.push(root);
        
        while(!nextLevel.empty()){
            currLevel = nextLevel;
            nextLevel = queue<TreeNode*>();
            
            int currSize = currLevel.size()-1;
            
            while(!currLevel.empty()){
                TreeNode* curr = currLevel.front();
                currLevel.pop();
                
                if(!currSize--) res.push_back(curr->val);
                if(curr->left) nextLevel.push(curr->left);
                if(curr->right) nextLevel.push(curr->right);    
            }
        }
        
        return res;
    }
};