class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0) return false;
        
        int num = 0;
        int curr = x;
        while(curr > 0){
            int r = curr%10;
            num = num * 10 + r;
            curr = curr/10;
        }
        return (num == x);
    }
}