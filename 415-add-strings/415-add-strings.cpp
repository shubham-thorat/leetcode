class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int i = num1.length()-1,j = num2.length()-1;
        int carry = 0;
        string str = "";
        while(i >=0 && j >=0){
            int sum  = (num1[i] - '0') + (num2[j] - '0') + carry;
            str = str + to_string(sum%10);
            carry = sum/10;
            i--;
            j--;
        }
        
        while(i >=0 ){
            int sum  = (num1[i] - '0') + carry;
            str = str + to_string(sum%10);    
            carry = sum/10;
            i--;
        }
        
        while(j >=0 ){
            int sum  = (num2[j] - '0') + carry;
            
            str = str + to_string(sum%10);
            carry = sum/10;
            j--;
        }
        
        if(carry != 0){
            str = str + to_string(carry);
        }
        reverse(str.begin(),str.end());
        return str;
    }
};