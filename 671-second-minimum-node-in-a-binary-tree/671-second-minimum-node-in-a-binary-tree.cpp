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
    void helper(TreeNode *root,set<int> &st) {
        if(!root) return;
        
        st.insert(root->val);
        helper(root->left,st);
        helper(root->right,st);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> st;
        
        helper(root,st);
        if(st.size() < 2) return -1;
       
        auto it = st.begin();
        it++;
        return(*it);
    }
};