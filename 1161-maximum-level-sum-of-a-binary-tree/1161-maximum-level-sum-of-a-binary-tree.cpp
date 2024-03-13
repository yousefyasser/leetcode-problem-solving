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
    vector<int> levelSum;
    
    int maxLevelSum(TreeNode* root) {
        int max = -1e6;
        int maxPos = 1;
        
        helper(root, 0);
        
        for(int i = 0; i < levelSum.size(); i++){
            if(max < levelSum[i]){
                max = levelSum[i];
                maxPos = i + 1;
            }
        }
        
        return maxPos;
    }
    
    void helper(TreeNode* curr, int currDepth){
        if(!curr) return;
        
        if(levelSum.size() == currDepth) levelSum.push_back(curr->val);
        else levelSum[currDepth] += curr->val;
        
        helper(curr->left, currDepth + 1);
        helper(curr->right, currDepth + 1);
    }
};