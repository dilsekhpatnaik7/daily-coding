// Problem Link: https://practice.geeksforgeeks.org/problems/9dacc32ad062be6e2ba8f6c41aad0b2b2376397d/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size(), k = costs[0].size();
        if(k == 1){
            if(n == 1)
                return costs[0][0];
            return -1;
        }
        pair<int,int> mini = {INT_MAX,-1}, smini = {INT_MAX,-1};
        for(int i = 0; i < k; i++){
            if(costs[0][i] < mini.first){
                smini = mini;
                mini = {costs[0][i], i};
            }
            else if(costs[0][i] < smini.first)
                smini = {costs[0][i], i};
        }
        
        for(int i = 1; i < n; i++){
            pair<int,int> curMini = {INT_MAX,-1}, curSmini = {INT_MAX,-1};
            
            for(int j = 0; j < k; j++){
                int x = costs[i][j];
                if(j != mini.second)
                    x += mini.first;
                else
                    x += smini.first;
                if(x < curMini.first){
                    curSmini = curMini;
                    curMini = {x, j};
                }
                else if(x < curSmini.first)
                    curSmini = {x, j};
            }
            mini = curMini;
            smini = curSmini;
        }
        return mini.first;
    }
};