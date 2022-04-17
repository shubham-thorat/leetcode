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
    
    void Inorder(TreeNode *root,vector<int> &o) {
        if(root == NULL) return;
        Inorder(root->left,o);
        o.push_back(root->val);
        Inorder(root->right,o);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> o;
        Inorder(root,o);
        TreeNode *t = new TreeNode(-1);
        TreeNode *d = t;
        
        for(auto &e:o){
            d->right = new TreeNode(e);
            d = d->right;
        }
        return t->right;
        
        
    }
};