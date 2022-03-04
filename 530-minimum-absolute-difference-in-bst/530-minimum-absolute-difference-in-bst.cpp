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
    void helper(TreeNode *root,int &min_diff,int &prev_value){
        if(root == NULL) return;
        
        helper(root->left,min_diff,prev_value);
        if(prev_value != INT_MAX){
            min_diff = min(min_diff,abs(prev_value - root->val));
        }
        prev_value = root->val;
        helper(root->right,min_diff,prev_value);
    }
    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX,prev_value = INT_MAX;
        
        helper(root,min_diff,prev_value);
        return min_diff;
    }
};