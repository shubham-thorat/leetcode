class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0,prevbeam = 0;
        for(int i=0;i<bank.size();i++){
            int count = 0;
            for(int j=0;j<bank[i].length();j++){
                if(bank[i][j] == '1'){
                    count += 1;
                }
            }
            if(count != 0){
                ans += prevbeam * count;
                prevbeam = count;
            }
        }
        return ans;
    }
};