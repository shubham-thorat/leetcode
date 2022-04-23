class Solution {
public:
    bool check(int mid,int mo,vector<int> &nums) {
        int cnt = 0;
        
        for(auto &e:nums) {
            if(e > mid) {
                cnt += (e%mid == 0) ? (e/mid) - 1 : (e/mid);
            }
            if(cnt > mo) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int mo) {
       
        int low = 1,high = INT_MIN; 
        
        for(auto &e:nums) {
            high = max(e,high);
        }
        int ans = -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            // cout << low << " " << high << endl;
            if(check(mid,mo,nums)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};