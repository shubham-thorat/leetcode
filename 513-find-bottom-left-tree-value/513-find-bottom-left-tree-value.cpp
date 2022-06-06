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
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*> levelNodes;
        int result;
        
        levelNodes.push(root);
        
        while(!levelNodes.empty()) {
            int levelSize = levelNodes.size();
            for(int i=0;i<levelSize;i++) {
                TreeNode *current = levelNodes.front();
                levelNodes.pop();
                
                if(i == 0) {
                    result = current->val;
                }
                if(current->left != NULL) {
                    levelNodes.push(current->left);
                }
                
                if(current->right != NULL) {
                    levelNodes.push(current->right);
                }
            }
        }
        return result;
    }
};