class Solution {
    public boolean search(int[] arr, int target) {
        int l = 0,h = arr.length - 1;
        
         while(l<=h)                                //  Loop When all elements are same except one              
           { int mid=(l+h)/2;
             if(arr[mid]==target ||arr[l]==target || arr[h]==target)
               return true;
             l++;h--;     
           }
        
        int low = 0,high = arr.length - 1;
        
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] == target){
                return true;
            }
            else if(arr[low] <= arr[mid]){
                if(target >= arr[low] && target < arr[mid]){
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if(target > arr[mid] && target <= arr[high]){
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
}