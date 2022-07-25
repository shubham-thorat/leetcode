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
    TreeNode* Inorder(TreeNode *root,vector<TreeNode*> &ans,unordered_set<int> &st) {
        if(root == NULL) {
            return NULL;
        }
        
        root->left = Inorder(root->left,ans,st);
        root->right = Inorder(root->right,ans,st);
        
        if(st.find(root->val) != st.end()) {
            if(root->left != NULL) {
                ans.push_back(root->left);
            }
            if(root->right != NULL) {
                ans.push_back(root->right);
            }
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == NULL) return {};
        unordered_set<int> st;
        for(auto &e:to_delete) st.insert(e);
        
        vector<TreeNode*> ans;
        if(st.find(root->val) == st.end()) {
            ans.push_back(root);
        }
        Inorder(root,ans,st);
        return ans;
    }
};