// Problem Link: https://leetcode.com/problems/gas-station/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, start = 0, current = 0;
        totalGas = accumulate(begin(gas), end(gas), 0);
        totalCost = accumulate(begin(cost), end(cost), 0);

        if(totalGas < totalCost) return -1;
        for(int i = 0; i < gas.size(); i++){
            current += gas[i] - cost[i];
            if(current < 0){
                start = i + 1;
                current = 0;
            }
        }
        return start;
    }
};