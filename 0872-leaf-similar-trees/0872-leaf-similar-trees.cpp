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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return leafSeq(root1) == leafSeq(root2);
    }
    
    vector<int> leafSeq(TreeNode* root){
        if(!root) return {};
        if(!(root->left) && !(root->right)) return {root->val};
        
        vector<int> left = leafSeq(root->left);
        vector<int> right = leafSeq(root->right);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};