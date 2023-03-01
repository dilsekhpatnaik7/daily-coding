// Problem Link: https://leetcode.com/problems/next-permutation/

// 1st Approach 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for(int i = n - 2; i >=0; i--) {
            if(nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            sort(nums.begin(), nums.end());
        }
        else {
            int nextGreater = index;
            for(int i = n - 1; i > index; i--) {
                if(nums[i] > nums[nextGreater]) {
                    nextGreater = i;
                    break;
                }
            }
            swap(nums[index], nums[nextGreater]);
            sort(nums.begin() + index + 1, nums.end());
        }
    }
};

// 2nd Approach using built-in library method
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(begin(nums), end(nums));
    }
};