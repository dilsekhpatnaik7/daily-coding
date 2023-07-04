// Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high) {
        int ans = INT_MAX;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }

    int findMin(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }
};