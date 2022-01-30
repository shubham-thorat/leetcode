typedef long long ll;
class Solution {
public:
    string subStrHash(string s, int power, int mod, int k, int hashvalue) {
        
        ll curr_hash = 0;
        ll computed = 1;
        for(int i=1;i<k;i++){
            computed = (computed * power)%mod;
        }
        string ret = "";
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if(i < n - k){
                curr_hash = (curr_hash - (s[i+k] - 'a' + 1)*computed)%mod;
                if(curr_hash < 0){
                    curr_hash += mod;
                }
            }
            
          curr_hash = (curr_hash * power + (s[i] - 'a' + 1))%mod;
            
            if(curr_hash == (ll)hashvalue && i <= n - k){
                ret = s.substr(i,k);
            }
        }
        return ret;
    }
};