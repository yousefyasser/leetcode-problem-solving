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
    int longestZigZag(TreeNode* root) {
        if(!root) return -1;
        
        stack<pair<TreeNode*, bool>> s;
        s.push({root->left,false});
        s.push({root->right,true});
        
        int ma = max(longestZigZag(root, true), longestZigZag(root, false));
        
        while(!s.empty()){
            pair<TreeNode*, bool> p = s.top();
            TreeNode* curr = p.first;
            bool left = p.second;
            s.pop();
            
            if(!curr) continue;
            
            ma = max(ma, longestZigZag(curr, left));
            
            s.push({curr->left, false});
            s.push({curr->right, true});
        }
        
        return ma;
    }
    
    int longestZigZag(TreeNode* curr, bool prevLeft){
        if(!curr) return -1;
        
        TreeNode* next;
        if(prevLeft){
            next = curr->right;
        }else{
            next = curr->left;
        }
        
        return 1 + longestZigZag(next, !prevLeft);
    }
};