/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void storeParent(unordered_map<TreeNode*,TreeNode*> &parent,TreeNode *A,TreeNode *currentParent) {
        if(A == NULL) {
            return;
        }
        
        if(currentParent != NULL) {
            parent[A] = currentParent;
        }
        
        storeParent(parent,A->left,A);
        storeParent(parent,A->right,A);
    }
    vector<int> distanceK(TreeNode* A, TreeNode* target, int C) {
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_set<TreeNode*> visited;
        
        storeParent(parent,A,NULL);
        
        queue<TreeNode*> levelNodes;
        
        levelNodes.push(target);
        visited.insert(target);
        while(levelNodes.empty()==false && C > 0) {
            int sz = levelNodes.size();
            while(sz--) {
                TreeNode *temp = levelNodes.front();
                levelNodes.pop();
                if(temp->left != NULL && visited.find(temp->left) == visited.end()) {
                    visited.insert(temp->left);
                    levelNodes.push(temp->left);
                }
                if(temp->right != NULL && visited.find(temp->right) == visited.end()) {
                    visited.insert(temp->right);
                    levelNodes.push(temp->right);
                }
                if(parent[temp] != NULL && visited.find(parent[temp]) == visited.end()) {
                    visited.insert(parent[temp]);
                    levelNodes.push(parent[temp]);
                }
            }
            C--;
        }
        
        vector<int> ans;
        while(levelNodes.empty() == false) {
            ans.push_back(levelNodes.front()->val);
            levelNodes.pop();
        }
        return ans;
    }
};

//[1]

//[0,8,3]

//[5]

//[6,2]