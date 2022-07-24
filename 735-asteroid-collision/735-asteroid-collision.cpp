class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        // [5,10,-5]
        // 5 10 
        vector<int> st;
        for(auto &e:ast) {
            if(e > 0) {
                st.push_back(e);
            }
            else {
                bool flag = true; 
                while(!st.empty() && st.back() > 0) {
                    if(st.back() < abs(e)) {
                        st.pop_back();
                    }
                    else if(st.back() == abs(e)) {
                        flag = false;
                        st.pop_back();
                        break;
                    }
                    else if(st.back() > abs(e)) {
                       flag = false;
                        break;
                    }
                }
                
                if(flag) st.push_back(e);
                
            }
        }
        return st;
        
    }
};