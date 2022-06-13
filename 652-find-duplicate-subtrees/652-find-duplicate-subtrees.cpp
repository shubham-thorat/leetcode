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
    string Inorder(TreeNode *root,vector<TreeNode*> &ans,unordered_map<string,int> &mp) {
        if(root == NULL) {
            return "#";
        }
        
        string temp = to_string(root->val) + "$";
        string l = Inorder(root->left,ans,mp);
        string r = Inorder(root->right,ans,mp);
        
        string str = temp + l + r;
        mp[str] += 1;
        if(mp[str] == 2) ans.push_back(root);
        
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root == NULL) return {};
        vector<TreeNode*> ans;
        unordered_map<string,int> mp;
        Inorder(root,ans,mp);
        return ans;
    }
};