// Problem Link: https://leetcode.com/problems/sort-an-array/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

// 1st Approach uses O(N * lg(N))
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// 2nd Approach uses O(N * lg(N))
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        stable_sort(nums.begin(), nums.end());
        return nums;
    }
};