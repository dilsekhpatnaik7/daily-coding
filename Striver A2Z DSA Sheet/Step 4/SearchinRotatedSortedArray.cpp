// Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]) {
                if((nums[low] <= target) && (target < nums[mid])) high = mid - 1;
                else low = mid + 1;
            }
            else {
                if((nums[mid] < target) && (target <= nums[high])) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};