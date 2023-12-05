// Problem Link: https://leetcode.com/problems/sort-colors/

// Dutch National Flag Algorithm which uses 3 pointers.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int t, low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high) {
            t = nums[mid];
            if(t == 0) swap(nums[low++], nums[mid++]);
            else if(t == 1) mid++;
            else if(t == 2) swap(nums[mid], nums[high--]);
        }
    }
};