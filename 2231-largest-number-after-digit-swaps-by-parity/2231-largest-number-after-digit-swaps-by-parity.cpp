class Solution {
public:
    int largestInteger(int num) {
     vector<int> odd,even,arr;
        while(num)
        {
            int digit =num%10;
            num=num/10;
            if(digit%2==0)
            {
                even.push_back(digit);
            }
            else
            {
                odd.push_back(digit);
            }
            arr.push_back(digit);
            
        }
        sort(even.rbegin(),even.rend());
        sort(odd.rbegin(),odd.rend());
        
        int o=0,e=0;
        int ans=0;
        int n=arr.size();
        for(int i=0;i<arr.size();i++)
        {
            if(arr[n-1-i]%2==0)
            {
                ans=ans*10+even[e++];
            }
            else
            {
                ans=ans*10+odd[o++];
            }
        }
        return ans;   
    }
};