// Problem Link: https://leetcode.com/problems/maximum-sum-circular-subarray/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int sum = nums[0], maxSoFar = nums[0], maxTotal = nums[0], minSoFar = nums[0], minTotal = nums[0];
        for(int i = 1; i < nums.size(); i++){
            maxSoFar = max(nums[i], maxSoFar + nums[i]);
            maxTotal = max(maxTotal, maxSoFar);
            
            minSoFar = min(nums[i], minSoFar + nums[i]);
            minTotal = min(minTotal, minSoFar);
            sum += nums[i];
        }
        if(sum == minTotal) return maxTotal;
        return max(sum - minTotal, maxTotal);
    }
};