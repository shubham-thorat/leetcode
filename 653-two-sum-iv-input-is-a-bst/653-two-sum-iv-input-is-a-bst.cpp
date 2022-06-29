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
    bool Inorder(TreeNode *root,int k,unordered_map<int,int> &mp) {
        if(root == NULL) return false;
        
        if(mp.find(k - root->val) != mp.end()) return true;
        mp[root->val] += 1;
        bool l = Inorder(root->left,k,mp);
        if(l) return true;
        bool r = Inorder(root->right,k,mp);
        return r;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> mp;
        
        return Inorder(root,k,mp);
    }
};