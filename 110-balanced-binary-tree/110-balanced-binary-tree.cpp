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
    int solve(TreeNode *root,bool &isbal) {
        if(root == NULL) return 0;
        
        int l = solve(root->left,isbal);
        
        int r = solve(root->right,isbal);
        if(abs(l-r) > 1) {
            isbal = false;
        }
        return max(l,r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool isbal = true;
        
        solve(root,isbal);
        return isbal;
    }
};