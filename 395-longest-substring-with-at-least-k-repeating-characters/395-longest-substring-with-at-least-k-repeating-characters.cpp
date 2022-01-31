class Solution {
public:
    int helper(string s,int low,int high,int k){
        if(low > high){
            return 0;
        }
        
        unordered_map<char,int> count;
        for(int i=low;i<=high;i++){
            count[s[i]] += 1;
        }
        
        for(int i=low;i<=high;i++){
            if(count[s[i]] < k){
                int opt1 = helper(s,low,i-1,k);
                int opt2 = helper(s,i+1,high,k);
                return max(opt1,opt2);
            }
        }
        
        return (high - low + 1);
    }
    int longestSubstring(string s, int k) {
      
        
        return helper(s,0,s.length() - 1,k);
    }
};

// a b a b a c b" k = 3
// 0 1 2 3 4 5 6
    
// a - 3
// b - 3
// d - 1