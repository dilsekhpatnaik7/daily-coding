// Problem Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> c(n, 1e8);
        c[src] = 0;
        for(int z = 0; z <= k; z++){
            vector<int> C(c);
            for(auto e: flights)
                C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
            c = C;
        }
        return c[dst] == 1e8 ? -1 : c[dst];
    }
};