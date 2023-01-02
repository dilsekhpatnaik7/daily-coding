// Problem Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > nums[(i+1) % nums.size()])
                count++;

            if(count > 1) return false;
        }
        return true;
    }
};