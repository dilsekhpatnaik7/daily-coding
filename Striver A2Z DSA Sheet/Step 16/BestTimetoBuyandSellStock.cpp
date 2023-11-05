/*
Problem Link: https://www.codingninjas.com/studio/problems/best-time-to-buy-and-sell-stock_893405?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices) {
    int mini = prices[0];
    int maxProfit = 0;
    for(int i = 0; i < prices.size(); i++) {
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}