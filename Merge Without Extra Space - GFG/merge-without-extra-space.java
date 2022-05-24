// { Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.io.*;

public class Main
{
    public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
		while(t-->0){
		    String inputLine[] = br.readLine().trim().split(" ");
		    int n = Integer.parseInt(inputLine[0]);
		    int m = Integer.parseInt(inputLine[1]);
		    long arr1[] = new long[n];
		    long arr2[] = new long[m];
		    inputLine = br.readLine().trim().split(" ");
		    for(int i=0; i<n; i++){
		        arr1[i] = Long.parseLong(inputLine[i]);
		    }
		    inputLine = br.readLine().trim().split(" ");
		    for(int i=0; i<m; i++){
		        arr2[i] = Long.parseLong(inputLine[i]);
		    }
		    Solution ob = new Solution();
		    ob.merge(arr1, arr2, n, m);
		    
		    StringBuffer str = new StringBuffer();
		    for(int i=0; i<n; i++){
		        str.append(arr1[i]+" ");
		    }
		    for(int i=0; i<m; i++){
		        str.append(arr2[i]+" ");
		    }
		    System.out.println(str);
		}
	}
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    //Function to merge the arrays.
    public static void swap(long arr1[],long arr2[],int lo,int hi) {
        long temp = arr1[lo];
        arr1[lo] = arr2[hi];
        arr2[hi] = temp;
    }
    public static void merge(long arr1[], long arr2[], int n, int m) 
    {
        // int fi = 0,se = 0;
        // while(fi < n) {
        //     if(arr1[fi] > arr2[0]) {
        //         long temp = arr1[fi];
        //         arr1[fi] = arr2[0];
        //         arr2[0] = temp;
                
        //         for(int i=1;i<m;i++) {
        //             if(arr2[i] < arr2[i-1]) {
        //                 long te = arr2[i];
        //                 arr2[i] = arr2[i-1];
        //                 arr2[i-1] = te;
        //             }
        //             else break;
        //         }
        //     }
        //     fi++;
        // } 
        
        int gap = (n+m);
        while(gap != 1) {
            
            if(gap %2 == 0) gap = gap/2;
            else gap = (gap + 1)/2;
            
            int fi = 0,se = gap;
            while(se < (n + m)) {
                if(se < n) {
                    if(arr1[fi] > arr1[se]) {
                        swap(arr1,arr1,fi,se);
                    }
                }
                else if(fi < n) {
                      if(arr1[fi] > arr2[se-n]) {
                        swap(arr1,arr2,fi,se-n);
                    }
                }
                else  {
                    if(arr2[fi-n] > arr2[se-n]) {
                        swap(arr2,arr2,fi-n,se-n);
                    }
                }
                fi++;
                se++;
            }
            
        }
        
        
    }
}
