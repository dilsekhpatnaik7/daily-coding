// Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestStreak = 0;
        unordered_set<int> hashSet;
        for(auto i: nums) {
            hashSet.insert(i);
        }

        for(auto i: nums) {
            if(!hashSet.count(i - 1)) {
                int currentNumber = i;
                int currentStreak = 1;
                while(hashSet.count(currentNumber + 1)) {
                    currentNumber++;
                    currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};