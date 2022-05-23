// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            
            int n = Integer.parseInt(read.readLine());
            String input[] = read.readLine().split(" ");
            
            int arr[] = new int[n];
            for(int i = 0;i<n;i++){
                arr[i] = Integer.parseInt(input[i]);
            }
            
            Solution ob = new Solution();
            System.out.println(ob.countTriplet(arr, n));
        }
    }
}// } Driver Code Ends


//User function Template for Java

class Solution {
    int lower_bound(int arr[],int lo,int hi,int val) {
        int mid = -1;
        while(lo < hi) {
            mid = lo + (hi - lo)/2;
            
            if(arr[mid] < val) {
                lo = mid + 1;
            }
            else  {
                hi = mid;
            }
        }
        
        if(val <= arr[lo]) {
            return lo;
        }
        if(val <= arr[hi]) {
            return hi;
        }
        return -1;
    }
    
    int upper_bound(int arr[],int lo,int hi,int val) {
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            if(arr[mid] <= val) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        
        if(val < arr[lo]) return lo;
        if(val < arr[hi]) return hi;
        return hi + 1;
  }
    int countTriplet(int arr[], int n) {
        // code here
        int count = 0;
        Arrays.sort(arr);
        
        for(int i=0;i<n-2;i++) {
            for(int j=i+1;j<n-1;j++) {
                int leftIdx =  lower_bound(arr,j+1,n-1,arr[i] + arr[j]);
                if(leftIdx == -1 || arr[leftIdx] != arr[i] + arr[j]) {
                    continue;
                }
                int rightIdx = upper_bound(arr,leftIdx,n-1,arr[i] + arr[j]);
                // System.out.println(arr[i] + " " + arr[j] + " " +  leftIdx + " " + rightIdx);
                count += rightIdx - leftIdx;
            }
        }
        return count;
    }
}