// Problem Link: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        unordered_map<int, int> mp;
        for(auto i: tasks){
            mp[i]++;
        }
        for(auto i: mp){
            if(i.second <= 1) return -1;
            else if(i.second == 2) ans++;
            else ans += ceil((double)i.second / 3.0);
        }
        return ans;
    }
};