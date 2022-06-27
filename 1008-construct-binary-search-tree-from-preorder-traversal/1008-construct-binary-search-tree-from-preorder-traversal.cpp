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
    TreeNode *buildBST(vector<int> &nums,int l,int r) {
        if(l > r) return NULL;
        
        TreeNode *root = new TreeNode(nums[l]);
        int mid = -1;
        for(int i=l+1;i<=r;i++) {
            if(nums[l] < nums[i]) {
                mid = i;
                break;
            }
        }
        
        if(mid == -1) {
            root->left = buildBST(nums,l+1,r);
            root->right = NULL;
        }
        else {
            root->left = buildBST(nums,l+1,mid - 1);
            root->right = buildBST(nums,mid,r);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return buildBST(preorder,0,preorder.size() - 1);
    }
};