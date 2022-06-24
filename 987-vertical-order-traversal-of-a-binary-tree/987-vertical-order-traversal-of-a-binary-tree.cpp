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
   vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,vector<pair<int,int>>>mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int num = q.front().second.second;
            int depth = q.front().second.first;
            q.pop();
            mp[num].push_back({depth,node->val});
            if(node->left)
                q.push({node->left,{depth+1,num-1}});
            if(node->right)
                q.push({node->right,{depth+1,num+1}});
        }
        for(auto m:mp){
            sort(m.second.begin(),m.second.end());
            vector<int>temp;
            for(auto it:m.second)
                temp.push_back(it.second);
            ans.push_back(temp);
        }
        return ans;
    }
};