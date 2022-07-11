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
    void solve(TreeNode *root,int depth,int &maxDepth,vector<int> &rightview) {
        if(root == NULL) {
            return;
        }
        
        if(depth > maxDepth) {
            maxDepth = depth;
            rightview.push_back(root->val);
        }
        
        solve(root->right,depth + 1,maxDepth,rightview);
        solve(root->left,depth + 1,maxDepth,rightview);
    }
    vector<int> rightSideView(TreeNode* root) {
        int depth = 0;
        int maxDepth = -1;
        
        vector<int> rightview;
        solve(root,depth,maxDepth,rightview);
        return rightview;
    }
};