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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        
        if(root->left == NULL && root->right == NULL  && root->val == targetSum) {
            return true;
        }
        
        bool l = hasPathSum(root->left,targetSum - root->val);
        
        if(l == true) {
            return true;
        }
        
        bool r = hasPathSum(root->right,targetSum - root->val);
        
        return r;
    }
};