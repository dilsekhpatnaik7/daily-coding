// Problem Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - (low / 2);
    }
};