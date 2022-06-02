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
    vector<int> distanceK(TreeNode* A, TreeNode* target, int C) {
        unordered_map<TreeNode*,TreeNode*> parents;
        // TreeNode *target = NULL;

        queue<TreeNode*> levelNodes;
        levelNodes.push(A);
        while(!levelNodes.empty()) {
            TreeNode *curr = levelNodes.front(); 
            levelNodes.pop();

            if(curr->left != NULL) {
                parents[curr->left] = curr;
                levelNodes.push(curr->left);
            }

            if(curr->right != NULL) {
                parents[curr->right] = curr;
                levelNodes.push(curr->right);
            }

        }
        // cout << "Not found " << levelNodes.size() << " " << target->val << " " <<endl;
        unordered_set<TreeNode*> vis;
        levelNodes.push(target);
        vis.insert(target);
        while(!levelNodes.empty() && C > 0) {
            int sz = levelNodes.size();
            // cout << "size " <<sz<<endl;
            C--;
            while(sz > 0) {
                sz--;
                TreeNode *curr = levelNodes.front();
                levelNodes.pop();

                if(curr->left != NULL && vis.find(curr->left) == vis.end()) {
                    levelNodes.push(curr->left);
                    vis.insert(curr->left);
                }

                if(curr->right != NULL && vis.find(curr->right) == vis.end()) {
                    levelNodes.push(curr->right);
                    vis.insert(curr->right);
                }
                if(parents[curr] != NULL && vis.find(parents[curr]) == vis.end()) {
                    levelNodes.push(parents[curr]);
                    vis.insert(parents[curr]);
                }
            }
         }    
    // cout <<"levelNodes size "<< levelNodes.size() <<endl;
        vector<int> result;
        while(!levelNodes.empty()) {
            TreeNode *t = levelNodes.front();
            // cout
            result.push_back(t->val);
            levelNodes.pop();
        }
        return result;
    }
};