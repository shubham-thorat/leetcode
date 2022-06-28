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
    bool isValidBSTUtil(TreeNode *root,TreeNode *minValue,TreeNode *maxValue) {
        if(root == nullptr) {
            return true;
        }
        
        if((minValue == nullptr || root->val > minValue->val) && (maxValue == nullptr || root->val < maxValue->val)) {
            bool l = isValidBSTUtil(root->left,minValue,root);
            bool r = isValidBSTUtil(root->right,root,maxValue);
            
            return (l&r);
        }
        else {
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        
        return isValidBSTUtil(root,nullptr,nullptr);
    }
};