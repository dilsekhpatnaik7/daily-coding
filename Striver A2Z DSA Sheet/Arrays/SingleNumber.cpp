// Problem Link: https://leetcode.com/problems/single-number/

// As the array is insorted we can use either Unordered-Set or XOR operator to find the single number.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto i: nums) {
            ans ^= i;
        }
        return ans;
    }
};