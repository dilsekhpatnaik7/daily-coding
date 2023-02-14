// Problem Link: https://practice.geeksforgeeks.org/problems/51b266505221b97522b1d2c86ddad1868a54831b/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        for(int i = N-2; i >= 0; i--){
            colors[i][0] += min(colors[i+1][1], colors[i+1][2]);
            colors[i][1] += min(colors[i+1][0], colors[i+1][2]);
            colors[i][2] += min(colors[i+1][0], colors[i+1][1]);
        }
        return min(colors[0][0], min(colors[0][1], colors[0][2]));
    }
};