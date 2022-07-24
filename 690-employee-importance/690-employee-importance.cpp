/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int Preorder(Employee *root,unordered_map<int,Employee*> &tree) {
        if(root == NULL) {
            return 0;
        }
        
        int ans = root->importance;
        vector<int> arr = root->subordinates;
        for(auto &e:arr) {
            ans += Preorder(tree[e],tree);
        }
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        
        Employee *root = NULL;
        unordered_map<int,Employee*> tree;
        for(int i=0;i<employees.size();i++) {
            if(employees[i]->id == id) {
                root = employees[i];
                // break;
            }
            tree[employees[i]->id] = employees[i];
        }
        
        if(root == NULL) return 0;
        
        return Preorder(root,tree);
    }
};