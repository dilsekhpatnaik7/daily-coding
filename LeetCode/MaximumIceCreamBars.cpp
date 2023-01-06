// Problem Link: https://leetcode.com/problems/maximum-ice-cream-bars/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum = 0;
        int i = 0;
        while(i < costs.size()) {
            sum += costs[i];
            if(sum > coins) break;
            i++;
        }
        return i;
    }
};