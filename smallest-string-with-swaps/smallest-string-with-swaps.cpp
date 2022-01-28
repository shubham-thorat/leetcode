class Solution {
public:
    class Union {
        public:
        int rank;
        int parent;
        Union(int rank,int parent){
            this->rank = rank;
            this->parent = parent;
        }
        Union(){
            
        }
    };
    int find(int src,vector<Union*> &nums){
        if(nums[src]->parent == src){
            return src;
        }
        else {
            return nums[src]->parent = find(nums[src]->parent,nums);
        }
    }
    void union_(int A,int B,vector<Union*> &nums){
        
        int groupA = find(A,nums);
        int groupB = find(B,nums);
        
        if(groupA != groupB){
            
            if(nums[groupA]->rank > nums[groupB]->rank){
                nums[groupB]->parent = groupA;
            }
            else if(nums[groupA]->rank < nums[groupB]->rank){
                nums[groupA]->parent = groupB;
            }
            else {
                nums[groupA]->rank += 1;
                nums[groupB]->parent = groupA;
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        
        vector<Union*> nums(n);
        for(int i=0;i<n;i++){
            nums[i] = new Union(1,i);
        }
        unordered_map<int,string> mp;
        for(int i=0;i<pairs.size();i++){
            union_(pairs[i][0],pairs[i][1],nums);
        }
        for(int i=0;i<n;i++){
            int index = find(i,nums);
            mp[index].push_back(s[i]);
        }
        
        for(auto &e:mp){
            sort(e.second.begin(),e.second.end(),greater<char>());
        }
        string ans = "";
        for(int i=0;i<n;i++){
            int index = find(i,nums);
            int len = mp[index].length();
            char ch = mp[index][len-1];
            mp[index].pop_back();
            ans.push_back(ch);
        }
        return ans;
        
    }
};