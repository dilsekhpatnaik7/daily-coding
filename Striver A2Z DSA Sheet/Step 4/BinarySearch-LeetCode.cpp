// Problem Link: https://leetcode.com/problems/binary-search/

class Solution {
public:
    int binarySearch(vector<int>& nums, int n, int target) {
        int low = 0, high = n - 1;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            else if(target > nums[mid]) low = mid + 1;
            else high = mid - 1; 
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binarySearch(nums, n, target);
    }
};