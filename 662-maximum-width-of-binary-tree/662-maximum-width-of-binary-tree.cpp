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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        long long maxWidth = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        
        
        while(!q.empty()) {
            int sz = q.size();
            long long minDist,maxDist;
            long long currMin = q.front().second;
            for(int i=0;i<sz;i++) {
                auto [curr,dist] = q.front();
                q.pop();
                dist = dist - currMin;
              
                if(i ==0) minDist = dist;
                if(i == sz - 1) maxDist =dist;
                if(curr->left) {
                    q.push({curr->left,2*dist + 1});
                }
                
                if(curr->right) {
                    q.push({curr->right,2*dist + 2});
                }
            }
            maxWidth = max(maxWidth,maxDist - minDist + 1);
        }
        return maxWidth;
    }
};