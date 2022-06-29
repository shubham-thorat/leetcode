class Solution {
public:
    static bool sortPeople(vector<int> &a,vector<int> &b) {
        if(a[0] != b[0]) return a[0] > b[0];
        else return a[1] < b[1];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(),people.end(),sortPeople);
        int n = people.size();
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++) {
            ans.insert(ans.begin() + people[i][1],people[i]);
        }
        return ans;
    }
};

// 0 -> [5,0],[7,0]
// 1 -> [6,1],[7,1]
// 2 -> [5,2]
// 4 -> [4,4]

//[5,0],[7,0]