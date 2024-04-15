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
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, "");
    }
    
    int sumNumbers(TreeNode* root, string curr){
        if(!root){
            return 0;
        }
        string val = curr + to_string(root->val);
        
        if(!root->left && !root->right){
            return stoi(val);
        }
        
        return sumNumbers(root->left, val) + sumNumbers(root->right, val);
    }
};