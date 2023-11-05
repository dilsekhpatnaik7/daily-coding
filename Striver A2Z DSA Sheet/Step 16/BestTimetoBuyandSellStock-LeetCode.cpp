/*
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++) {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};