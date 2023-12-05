// Problem Link: https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int binarySearch(vector<int>& nums, int low , int high) {
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if((nums[mid] > nums[mid - 1]) && (nums[mid] > nums[mid + 1])) return mid;

            if(nums[mid] > nums[mid - 1]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n - 1] > nums[n - 2]) return n - 1;

        return binarySearch(nums, 1 , n - 2);
    }
};