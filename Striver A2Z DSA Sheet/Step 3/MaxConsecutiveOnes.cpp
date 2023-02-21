// Problem Link: https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                c++;
                ans = max(ans, c);
            }
            else {
                c = 0;
            }
        }
        return ans;
    }
};