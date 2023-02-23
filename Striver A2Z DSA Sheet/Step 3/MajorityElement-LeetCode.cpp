// Problem Link: https://leetcode.com/problems/majority-element/

//Moore Voting Algorithm LeetCode
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for(auto num:nums){
            if(count == 0) candidate = num;
            if(candidate == num) count++;
            else count--;
        }
        return candidate;
    }
};