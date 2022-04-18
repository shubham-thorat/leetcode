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
    int helper(TreeNode *root,int k,int &index){
        if(root == NULL) return -1;
        
        int l = helper(root->left,k,index);
        if(l != -1) return l;
        index++;
        if(index == k) return root->val;
        int r = helper(root->right,k,index);
        
        return r;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int index = 0;
        
        return helper(root,k,index);
    }
};