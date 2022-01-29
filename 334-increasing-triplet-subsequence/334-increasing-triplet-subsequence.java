class Solution {
    public int lower_bound(ArrayList<Integer> lis,int num){
        if(lis.size() == 0) return 0;
        int ans = 0;
        int low = 0,high = lis.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(lis.get(mid) > num){
                high = mid - 1;
            }
            else {
                ans = mid;
                low = mid + 1;
            }
        }
        
        if(ans < lis.size() && lis.get(ans) < num){
            ans++;
        }
        return ans;
    }
    public boolean increasingTriplet(int[] nums) {
        
        ArrayList<Integer> lis = new ArrayList<Integer>();
        
        for(int e:nums){
            int index = lower_bound(lis,e);
            if(index == lis.size()){
                lis.add(e);
            }
            else {
                lis.set(index,e);
            }
            if(lis.size() == 3) return true;
        }
        return false;
    }
}