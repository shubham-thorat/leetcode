class Solution {
    StringBuilder AddNumber(StringBuilder sb1,StringBuilder sb2){
        int i = sb1.length() - 1;
        int j = sb2.length() - 1;
        int carry = 0;
        int num = 0;
        System.out.println(sb1.toString() + " :  " + sb2.toString());
        StringBuilder sb = new StringBuilder();
        while(i>=0 && j >=0){
            num = (sb1.charAt(i) - '0') + (sb2.charAt(j) - '0') + carry;
            
            sb.append(String.valueOf(num%10));
            carry = num/10;
            i--;
            j--;
        }
        
        while(i>=0){
            num = (sb1.charAt(i) - '0') + carry;
            sb.append(String.valueOf(num%10));
            carry = num/10;
            i--;
        }
        
        while(j>=0){
            num = (sb2.charAt(j) - '0') + carry;
            sb.append(String.valueOf(num%10));
            carry = num/10;
            j--;
        }
        if(carry != 0){
            sb.append(String.valueOf(carry));
        }
        System.out.println();
        
        System.out.println(sb.toString());
        return sb.reverse();
    }
    public String multiply(String num1, String num2) {
        StringBuilder add = new StringBuilder("");
        int n = num1.length();
        int m = num2.length();
       
        
        StringBuilder zero = new StringBuilder("");
        for(int i=n-1;i>=0;i--){
            int num = (num1.charAt(i) - '0');
            StringBuilder sb2 = new StringBuilder();
            int carry = 0;
            for(int j=m-1;j>=0;j--){
                int prod = num * (num2.charAt(j) - '0') + carry;
                
                sb2.append(String.valueOf(prod%10));
                carry = (prod/10);
                System.out.print(prod + " , " + carry + " ) ( ");
            }
            if(carry != 0)
                sb2.append(String.valueOf(carry));
            sb2 = sb2.reverse();
            sb2.append(zero);
            add = AddNumber(add,sb2);
            zero.append("0");
        }
        
        int index = 0;
        while(index < add.length() - 1){
            if(add.charAt(index) == '0'){
                index++;
            }
            else break;
        }
        return add.toString().substring(index);
    }
}