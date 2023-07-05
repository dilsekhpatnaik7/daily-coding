// Problem Link: https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        int profit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};