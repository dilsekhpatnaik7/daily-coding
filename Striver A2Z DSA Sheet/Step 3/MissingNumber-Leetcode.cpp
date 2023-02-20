// Problem Link: https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actualSum = 0, givenSum = 0;
        actualSum = (n * (n + 1)) / 2;
        for(int i = 0; i < n; i++) {
            givenSum += nums[i];
        }
        return actualSum - givenSum;
    }
};