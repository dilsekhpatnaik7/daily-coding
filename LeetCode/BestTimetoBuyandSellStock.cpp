// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX, sell = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            buy = min(buy, prices[i]);
            sell = max(sell, prices[i]-buy);
        }
        return sell;
    }
};