// Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool binarySearch(vector<int>& nums, int low, int high, int target) {
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(target == nums[mid]) return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            if(nums[low] <= nums[mid]) {
                if((nums[low] <= target) && (target < nums[mid])) high = mid - 1;
                else low = mid + 1;
            }
            else {
                if((nums[mid] < target) && (target <= nums[high])) low = mid + 1;
                else high = mid - 1;
            }
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};