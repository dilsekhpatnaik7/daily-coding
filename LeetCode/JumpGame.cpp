// Problem Link: https://leetcode.com/problems/jump-game/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal=nums.size()-1;
        int n=nums.size()-1;
        for(int i=n;i>=0;i--){
            if(i+nums[i]>=goal){
                goal=i;
            }
        }
        if(goal==0)return true;
        return false;
    }
};