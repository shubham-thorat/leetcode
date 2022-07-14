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
    TreeNode* solve(vector<int> &nums,unordered_map<int,int> &mp,int l,int r,int &index) {
        if(l > r) return NULL;
        
        int mid = mp[nums[index]];
        TreeNode *root = new TreeNode(nums[index++]);
        
        root->left = solve(nums,mp,l,mid - 1,index);
        root->right  = solve(nums,mp,mid + 1,r,index);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<inorder.size();i++) {
            mp[inorder[i]] = i;
        }
        
        int index = 0;
        return solve(preorder,mp,0,inorder.size() - 1,index);
    }
};