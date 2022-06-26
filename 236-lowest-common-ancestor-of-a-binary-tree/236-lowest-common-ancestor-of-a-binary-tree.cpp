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
    bool existsNode(TreeNode *root,TreeNode *node) {
        if(root == NULL) {
            return false;
        }
        
        if(root == node || existsNode(root->left,node) || existsNode(root->right,node)) {
            return true;
        }
        else {
            return false;
        }
    }
    TreeNode *findLCA(TreeNode *root,TreeNode *p,TreeNode *q) {
        if(root == NULL) {
            return NULL;
        }
        
        if(root == p || root == q) {
            return root;
        }
        
        TreeNode *l = findLCA(root->left,p,q);
        TreeNode *r = findLCA(root->right,p,q);
        if(l != NULL && r != NULL) {
            return root;
        }
        else if(l != NULL) {
            return l;
        }
        else {
            return r;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!existsNode(root,p) || !existsNode(root,q)) {
            return NULL;
        }
        
        return findLCA(root,p,q);
    }
};