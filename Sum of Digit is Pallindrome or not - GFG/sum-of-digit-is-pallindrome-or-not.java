// { Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());
            Solution ob = new Solution();
            System.out.println(ob.isDigitSumPalindrome(N));
        }
    }
}// } Driver Code Ends


// User function Template for Java

class Solution {
    int isDigitSumPalindrome(int N) {
        
        
        
        
         String s=String.valueOf(N);
        
        int result = 1;
        int sum =0;
        for(int i =0; i<s.length(); i++)
        {
            sum = sum + (s.charAt(i)- '0');
        }
        
        String p = String.valueOf(sum);
        
        for(int i =0; i<p.length(); i++){
             if(p.charAt(i) == p.charAt(p.length()-1-i)){
                result = 1;
            }
            else{
                result = 0;
                break;
            }
        }
       
        return result;
        
    }
}