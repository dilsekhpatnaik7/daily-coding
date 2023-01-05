// Problem Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](const auto &x, const auto &y) {
        return x[1] < y[1];});
        int ret = 1, cur = a[0][1];
        for (int i = 1; i < a.size(); i++) {
            if (cur < a[i][0]) {
                cur = a[i][1];
                ret++; 
            }
        }
        return ret;
    }
};