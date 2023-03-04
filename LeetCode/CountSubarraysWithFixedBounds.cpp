// Problem Link: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int leftBound = -1;
        int lastMin = -1, lastMax = -1;
        long long count = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] >= minK && nums[i] <= maxK) {
                lastMin = (nums[i] == minK) ? i : lastMin;
                lastMax = (nums[i] == maxK) ? i : lastMax;
                count += max(0, min(lastMin, lastMax) - leftBound);
            } 
            else {
                leftBound = i;
                lastMin = -1;
                lastMax = -1;
            }
        }
        return count;
    }
};