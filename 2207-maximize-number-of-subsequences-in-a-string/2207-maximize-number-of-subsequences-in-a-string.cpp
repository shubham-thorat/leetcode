class Solution {
public:
   
    long long maximumSubsequenceCount(string s, string p) {
       long long ans = 0, maxi = 0;
        long long cnt = 1;
        //Assume adding 0th character of pattern at starting
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == p[1]) ans += cnt;
            if (s[i] == p[0]) cnt++;
        }
        maxi = max(maxi, ans);
        ans = 0; cnt = 1;
        //Assume adding second character of pattern at end
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == p[0]) ans += cnt;
            if (s[i] == p[1]) cnt++;
        }
        maxi = max(maxi, ans);
        return maxi;
    }
};