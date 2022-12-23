// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int buy = INT_MIN;
        int sell = 0;
        int rest = 0;
        for (int p : prices) {
            buy = max(buy, rest - p);
            rest = max(rest, sell);
            sell = max(sell, buy + p);
        }
        return sell;
    }
};