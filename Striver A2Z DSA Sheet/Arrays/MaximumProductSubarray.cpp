// Problem Link: https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, currentProduct = 1;
        for(int i = 0; i < nums.size(); i++) {
            currentProduct *= nums[i];
            ans = max(ans, currentProduct);
            if(currentProduct == 0) currentProduct = 1;
        }
        currentProduct = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            currentProduct *= nums[i];
            ans = max(ans, currentProduct);
            if(currentProduct == 0) currentProduct = 1;
        }
        return ans;
    }
};