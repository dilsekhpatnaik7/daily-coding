// Problem Link: https://leetcode.com/problems/fair-distribution-of-cookies/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    void helper(int ind, const vector<int>& cookies, vector<int>& gotC, int k, int& ans) {
        int n = cookies.size();
        if(ind == n) {
            int currMax = INT_MIN;
            for(int i = 0; i < k; i++) {
                currMax = max(currMax, gotC[i]);
            }
            ans = min(ans, currMax);
            return;
        }

        for(int i = 0; i < k; i++) {
            gotC[i] += cookies[ind]; 
            helper(ind + 1, cookies, gotC, k, ans);
            gotC[i] -= cookies[ind];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        vector<int> gotC(k, 0);
        helper(0, cookies, gotC, k, ans);
        return ans;
    }
};