// Problem Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int posIndex = 0, negIndex = 1;
        for(auto i: nums) {
            if(i >= 0) {
                ans[posIndex] = i;
                posIndex += 2;
            }
            if(i < 0){
                ans[negIndex] = i;
                negIndex += 2;
            }
        }
        return ans;
    }
};