class Solution {
public:
    string Positive(string n,int x) {
        string ans = "";
        bool inserted = false;
        for(int i=0;i<n.length();i++) {
            
            if(inserted == false && ((n[i] - '0') < x)) {
                ans.push_back(x + '0');
                inserted = true;
            } 
            ans.push_back(n[i]);
        }
        if(inserted == false) ans.push_back(x + '0');
        return ans;
    }
    string Negative(string n,int x) {
        string ans = "-";
        bool inserted = false;
        for(int i=1;i<n.length();i++) {
            
            if(inserted == false && ((n[i] - '0') > x)) {
                ans.push_back(x + '0');
                inserted = true;
            } 
            ans.push_back(n[i]);
        }
        if(inserted == false) ans.push_back(x + '0');
        return ans;
    }
    string maxValue(string n, int x) {
        
        int size = n.length();
        if(size == 0) return to_string(x);
        
        if(n[0] == '-') return Negative(n,x);
        else return Positive(n,x);
    }
};