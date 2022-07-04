class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sizeNums = nums.size();
        
        int maxProduct = INT_MIN;
//         for(int i=0;i<sizeNums;i++) {
//             int currentProduct = 1;
//             for(int j=i;j<sizeNums;j++) {
//                 currentProduct = currentProduct * nums[j];
                
//                 maxProduct = max(maxProduct,currentProduct);
//             }
//         }
//         return maxProduct;
        
        int currentProduct = 1;
        for(int i=0;i<sizeNums;i++) {
            currentProduct = currentProduct * nums[i];
            
            maxProduct = max(maxProduct,currentProduct);
            
            if(currentProduct == 0) {
                currentProduct = 1;
            }
        }
        
        currentProduct = 1;
        for(int i=sizeNums-1;i>=0;i--) {
            currentProduct = currentProduct * nums[i];
            
            maxProduct = max(maxProduct,currentProduct);
            
            if(currentProduct == 0) {
                currentProduct = 1;
            }
        }
        
        return maxProduct;
    }
};

// O(n^2)
// O(1)


// [2,3,-2,4]

//claim -> assumption ->

// maxProduct =