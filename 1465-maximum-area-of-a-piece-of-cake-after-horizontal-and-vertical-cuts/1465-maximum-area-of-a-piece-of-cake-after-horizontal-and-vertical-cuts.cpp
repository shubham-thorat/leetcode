class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        long long mod = 1e9 + 7;
        int x=INT_MIN,y=INT_MIN;

        if(horizontalCuts.size()==1) x = max(horizontalCuts[0],h-horizontalCuts[0]);
        else {
            sort(horizontalCuts.begin(),horizontalCuts.end());
            x = horizontalCuts[0];
            for(int i=0;i<horizontalCuts.size()-1;i++){
                x = max(x,horizontalCuts[i+1]-horizontalCuts[i]);
            }
            x = max(x,h-(int)horizontalCuts[horizontalCuts.size()-1]);
        }

        
        if(verticalCuts.size()==1) y = max(verticalCuts[0],w-verticalCuts[0]);
        else {
            sort(verticalCuts.begin(),verticalCuts.end());
            y = verticalCuts[0];
            for(int i=0;i<verticalCuts.size()-1;i++){
                y = max(y,verticalCuts[i+1]-verticalCuts[i]);
            }
            y = max(y,w-verticalCuts[verticalCuts.size()-1]);
        }

        return ((x%mod) * (y%mod))%mod;
    }
};