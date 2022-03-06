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
    void helper(TreeNode *root,string str,vector<string> &ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            str += to_string(root->val);
            ans.push_back(str);
            return;
        }
        
        str += to_string(root->val);
        str += "->";
        
        helper(root->left,str,ans);
        helper(root->right,str,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str = "";
        helper(root,str,ans);
        return ans;
    }
};