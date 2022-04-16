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
    int findSum(TreeNode *root) {
        if(root == NULL) return 0;
        
        return root->val + findSum(root->left) + findSum(root->right);
    } 
    TreeNode *helper(int &sum,TreeNode *root) {
        if(root == NULL) return root;
        
        TreeNode *l = helper(sum,root->left);
        int v = root->val;
        // cout << v << " ";
        root->val = sum;
        // cout << root->val << endl;
        sum = sum - v;
        TreeNode *r = helper(sum,root->right);
        return root;
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = findSum(root);
        // cout << sum << endl;
        return helper(sum,root);
    }
};