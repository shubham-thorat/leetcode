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
    TreeNode *findMinRight(TreeNode *root) {
        while(root->left != NULL) {
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL) {
            return root;
        }
        
        if(root->val == key) {
            if(root->left == NULL) {
                TreeNode *current = root;
                root =  root->right;
                delete current;
            }
            else if(root->right == NULL){
                TreeNode *current = root;
                root =  root->left;
                delete current;
            }
            else {
                TreeNode *rightMin = findMinRight(root->right);
                swap(root->val,rightMin->val);
                root->right = deleteNode(root->right,key);
            }
        }
        else {
            if(key < root->val) {
                root->left  = deleteNode(root->left,key);
            }
            else {
                root->right = deleteNode(root->right,key);
            }
        }
        return root;
    }
};