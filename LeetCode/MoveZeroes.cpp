// Problem Link: https://leetcode.com/problems/move-zeroes/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }
        while(index < nums.size()){
            nums[index++] = 0;
        }
    }
};