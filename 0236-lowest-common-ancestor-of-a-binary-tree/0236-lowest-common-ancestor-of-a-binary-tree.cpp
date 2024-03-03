/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1 = getPath(root, p);
        vector<TreeNode*> path2 = getPath(root, q);
        
        int len1 = path1.size();
        int len2 = path2.size();
        
        int pos1 = max(0, len1 - len2);
        int pos2 = max(0, len2 - len1);
        
        while(path1[pos1++] != path2[pos2++]){}
            
        return path1[pos1-1];
    }
    
    vector<TreeNode*> getPath(TreeNode* curr, TreeNode* target){
        if(!curr) return {};
        if(curr == target) return {target};
        
        vector<TreeNode*> left = getPath(curr->left, target);
        vector<TreeNode*> right = getPath(curr->right, target);
        
        if(!left.size() && !right.size()) return {};
        
        if(right.size()){
            right.push_back(curr);
            return right;
        }
        
        left.push_back(curr);
        return left;
    }
};