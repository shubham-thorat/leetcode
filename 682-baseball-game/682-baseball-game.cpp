class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
        
        for(int i=0;i<ops.size();i++) {
            string e = ops[i];
            if(e == "C"){
                st.pop();
            }
            else if(e == "D"){
                int num = st.top();
                st.push(num *1LL* 2);
            }
            else if(e == "+"){
                int n1 = st.top(); st.pop();
                int n2 = st.top();
                st.push(n1);
                st.push(n1 + n2);
            }
            else {
                st.push(stoi(e));
            }
        }
        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};