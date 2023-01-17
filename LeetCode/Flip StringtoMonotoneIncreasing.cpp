// Problem Link: https://leetcode.com/problems/flip-string-to-monotone-increasing/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0, flip = 0;
        for(auto i: s){
            if(i == '1') flip++;
            else ans++;
            ans = min(ans, flip);
        }
        return ans;
    }
};