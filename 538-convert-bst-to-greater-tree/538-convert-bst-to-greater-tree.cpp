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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> st;
        TreeNode *node = root;
        while(!st.empty() || node != NULL) {
            while(node != NULL) {
                st.push(node);
                node = node->right;
            }
            
            node = st.top();
            st.pop();
            // node->val = sum;
            sum += node->val;
            node->val = sum;
            node = node->left;
        }
        return root;
    }
};