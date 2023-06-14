// Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    int binarySearch(vector<int> nums, int n, int target, bool findStartIndex) {
        int low = 0, high = n - 1, ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                ans = mid;
                if(findStartIndex) high = mid - 1;
                else low = mid + 1;
            }
            else {
                if(nums[mid] < target) low = mid + 1;
                else high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums, nums.size(), target, true), binarySearch(nums, nums.size(), target, false)};
    }
};