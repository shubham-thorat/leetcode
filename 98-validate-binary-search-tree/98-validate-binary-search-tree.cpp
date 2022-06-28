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
    bool isValidBSTUtil(TreeNode *root,long long minValue,long long maxValue) {
        if(root == NULL) {
            return true;
        }
        
        if(root->val > minValue && root->val < maxValue) {
            return isValidBSTUtil(root->left,minValue,root->val) && isValidBSTUtil(root->right,root->val,maxValue);
        }
        else {
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        long long inf = 1e12;
        return isValidBSTUtil(root,-inf,inf);
    }
};