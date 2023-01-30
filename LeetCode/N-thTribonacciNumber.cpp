// Problem Link: https://leetcode.com/problems/n-th-tribonacci-number/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int tribonacci(int n) {
        vector<int> ans{0,1,1};
        for(int i=3;i<=n;i++){
            ans.push_back(ans[i-1]+ans[i-2]+ans[i-3]);
        }
        return ans[n];
    }
};