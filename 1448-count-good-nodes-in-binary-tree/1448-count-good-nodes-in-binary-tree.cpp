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
    int goodNodes(TreeNode* root) {
        return solve(root->val, root);
    }
    
    int solve(int maxSoFar, TreeNode* curr){
        if(!curr) return 0;
        
        maxSoFar = max(maxSoFar, curr->val);
        int cand1 = solve(maxSoFar, curr->left);
        int cand2 = solve(maxSoFar, curr->right);
        return (curr->val == maxSoFar) + cand1 + cand2;
    }
};