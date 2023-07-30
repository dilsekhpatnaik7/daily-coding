/*
Exactly Same As: Allocate Books
Problem Link: https://leetcode.com/problems/split-array-largest-sum/

Time Complexity: O(N * log(N))
Space Cmplexity: O(1)
*/

class Solution {
public:
    bool canSplit(vector<int>& nums, long long capacitySum, int ways) {
        int n = nums.size(), calculatingWays = 1, capacity = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] + capacity <= capacitySum) capacity += nums[i];
            else {
                calculatingWays++;
                capacity = nums[i];
            }
            if(calculatingWays > ways) return true;
        }
        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(canSplit(nums, mid, k)) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};