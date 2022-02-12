class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> person;
        for(int i=1;i<=n;i++){
            person.insert(i);
        }
        
        for(auto e:trust){
            int a = e[0];
            int b = e[1];
            if(person.find(a) != person.end()){
                person.erase(a);
            }
        }
        
        if(person.size() == 1) {
            int expected = -1;
            for(auto e:person){
                expected = e;
                break;
            }
            unordered_set<int> st;
            for(auto e:trust){
                if(e[1] == expected) st.insert(e[0]);
            }
            if(st.size() == n-1) return expected;
        }
        return -1;
    }
};