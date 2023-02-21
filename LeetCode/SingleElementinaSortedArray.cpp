// Problem Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

// 1st Approach using Unordered Map counting the frequencies.
// TC: O(n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        for(auto i: map) {
            if(i.second == 1) return i.first;
        }
        return -1;
    }
};

// 2nd Approach using XOR operator a^a = 0 && a^0 = a
// TC: O(n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int r = 0;
        for(auto i:nums) r^ = i;
        return r;
    }
};

// 3rd Approach which is optimal. As the array is sorted we use Binary Search
// TC: O(log n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right)/2;
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};