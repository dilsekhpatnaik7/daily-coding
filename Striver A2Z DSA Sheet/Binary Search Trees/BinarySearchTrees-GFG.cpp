/*
Problem Link: https://www.geeksforgeeks.org/problems/binary-search-trees/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
  public:
    bool isBSTTraversal(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= nums[i - 1]) return false;
        }
    return true;
    }
};