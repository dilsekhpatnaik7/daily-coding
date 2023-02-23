// Problem Link: https://leetcode.com/problems/maximum-subarray/

// Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = INT_MIN;
        for(auto n: nums){
            sum += n;
            maxSum = max(maxSum, sum);
            if(sum < 0) sum=0;
        }
        return maxSum;
    }
};