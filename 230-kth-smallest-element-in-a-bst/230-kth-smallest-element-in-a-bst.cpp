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
    TreeNode* kthSmallestUtil(TreeNode *root,int k,int &countNode) {
        if(root == NULL) {
            return NULL;
        }
        
        TreeNode *l = kthSmallestUtil(root->left,k,countNode);
       
        if(l != NULL) {
            return l;
        }
        
        countNode++;
        if(countNode == k) {
            return root;
        }
        
        TreeNode *r = kthSmallestUtil(root->right,k,countNode);
        
        return r;
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int countNode = 0;
        
        TreeNode *node = kthSmallestUtil(root,k,countNode);
        return node->val;
    }
};