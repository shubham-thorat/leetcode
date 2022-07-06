class Solution {
public:
    void permuteUtil(vector<int> &nums,int index,vector<vector<int>> &possiblePermutations) {
        
        if(index == nums.size()) {
            possiblePermutations.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++) {
            swap(nums[i],nums[index]);
            permuteUtil(nums,index + 1,possiblePermutations);
            swap(nums[i],nums[index]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> possiblePermutations;
        
        permuteUtil(nums,0,possiblePermutations);
        return possiblePermutations;
    }
};

//             [1,2,3]
//     [1,2,3]         [2,1,3]     [3,1,2]
    
// [1,2,3] [1,3,2]     [2,1,3] [2,3,1] [3,1,2] [3,2,1]