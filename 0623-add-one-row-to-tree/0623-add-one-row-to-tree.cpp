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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            return new TreeNode(val, root, nullptr);    
        }
        
        updateTree(root, val, depth - 1);
        return root;
    }
    
    void updateTree(TreeNode* curr, int val, int depth){
        if(!curr)
            return;
        
        if(depth == 1){
            curr->left = new TreeNode(val, curr->left, nullptr);    
            curr->right = new TreeNode(val, nullptr, curr->right);
            return;
        }
        
        updateTree(curr->left, val, depth - 1);
        updateTree(curr->right, val, depth - 1);
    }
};