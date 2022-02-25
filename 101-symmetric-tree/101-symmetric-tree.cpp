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
    bool isSymmetric(TreeNode* root) {
        list<TreeNode*> q;
        q.push_back(root);
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                
                TreeNode *curr  = q.front(); q.pop_front();
                if(curr != NULL) {
                     q.push_back(curr->left);
                     q.push_back(curr->right);
                }
            }
            
            auto it1 = q.begin();
            auto it2 = q.end();
            it2--;
            int i = 0,j=q.size();
            while(i < j){
                if((*it1) == NULL && (*it2) == NULL){
                    
                }
                else if((*it1) == NULL || (*it2) == NULL){
                    return false;
                }
                else if((*it1)->val != (*it2)->val){
                    return false;
                }
                it1++;
                it2--;
                i++;
                j--;
            }
        }
        return true;
    }
};