class Solution {
public:
    vector<string> split(string &str,char del) {
        vector<string> res;
        string temp = "";
        for(int i=0;i<str.length();i++){
            if(str[i] == del) {
                if(temp.size() != 0)
                    res.push_back(temp);
                temp = "";
            }
            else {
                temp.push_back(str[i]);
            }
        }
        
        if(temp.size() != 0) res.push_back(temp);
        return res;
    }
    string simplifyPath(string str) {
        vector<string> ans = split(str,'/');
        stack<string> res;

        for(auto &e:ans) {
            if(e == ".."){
                if(res.size() != 0) res.pop();
            }
            else if(e == ".") {

            }
            else {
                res.push(e);
            }
        }

        vector<string> temp;
        while(!res.empty()) {
            temp.push_back(res.top());
            res.pop();
        }
        string result = "";
        reverse(temp.begin(),temp.end());
        for(auto &e:temp) {
            result.push_back('/');
            result = result + e;
        }

        if(result.size() == 0) result.push_back('/');

        return result;
    }
};