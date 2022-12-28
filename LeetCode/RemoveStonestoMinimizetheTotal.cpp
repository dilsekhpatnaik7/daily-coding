// Problem Link: https://leetcode.com/problems/remove-stones-to-minimize-the-total/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pilesPQ;
        int totalSum = 0;
        for(auto pile : piles){
            pilesPQ.push(pile);
            totalSum += pile;
        }
        for(int i = 0; i < k; i++){
            int top = pilesPQ.top();
            pilesPQ.pop();
            pilesPQ.push(int(ceil(top/2.0)));
            totalSum -= int(floor(top/2.0));
        }
        return totalSum;
    }
};