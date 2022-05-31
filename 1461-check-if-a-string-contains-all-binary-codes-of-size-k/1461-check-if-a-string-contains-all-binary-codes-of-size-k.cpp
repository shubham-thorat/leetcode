typedef long long ll;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = ((1<<k));
//        ll sum = (n * (n+1))/2;
//         unordered_set<ll> st;
        
//         int curr_num = 0;
//         for(int i=0;i<k-1;i++) {
//             curr_num = curr_num 
//         }
//         for(int i=0;i<s.length();i++) {
            
//         }
        if(k > s.length()) return 0;
        
        unordered_set<string> st;
        
        for(int i=0;i<=s.length()-k;i++) {
            st.insert(s.substr(i,k));
        }
        
        return (st.size() == n);
    }
};

// "01" "00" "10" "11"

// 00 
// 01 
// 10 
// 11
    
// n = 2^2 - 1
//   n * (n + 1)/2;

// umap => 0,1,3,2

// sum = 0 + 1 + 3 +  2
    
    
// "00110110"
