class StockSpanner {
public:
    deque<int> q;
    vector<int> nums;
    StockSpanner() {
        
    }
    
    int next(int price) {
        nums.push_back(price);
        int n = nums.size();
        while(!q.empty() && nums[q.back()] <= price) {
            q.pop_back();
        }
        int ans = 0;
        if(q.empty()) {
            ans = n;
        }
        else {
            ans = n - 1 - q.back();
        }
        q.push_back(n - 1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */