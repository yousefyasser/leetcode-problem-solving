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

using ll = long long;
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        stack<TreeNode*> s;
        s.push(root);
        int res = 0;
        
        while(!s.empty()){
            TreeNode* curr = s.top();
            s.pop();
            
            if(!curr) continue;
            
            s.push(curr->left);
            s.push(curr->right);
            
            res += pathSum(curr, targetSum, 0);
        }
        
        return res;
    }
    
    int pathSum(TreeNode* curr, int targetSum, ll sum){
        if(!curr) return 0;
        
        int cand1 = pathSum(curr->left, targetSum, sum + curr->val);
        int cand2 = pathSum(curr->right, targetSum, sum + curr->val);
        
        return cand1 + cand2 + (targetSum == sum + curr->val);
    }
};