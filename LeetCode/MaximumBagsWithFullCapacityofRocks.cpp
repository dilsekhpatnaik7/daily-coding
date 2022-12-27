// Problem Link: https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> v;
        for(int i = 0; i < capacity.size(); i++) {
            v.push_back(capacity[i]-rocks[i]);
        }
        sort(v.begin(), v.end());
        int res = 0;
        int cnt = 0;
        for(auto it : v) {
            res+=it;
            if(res>additionalRocks)
                break;
            else
                cnt++;
        }
        return cnt;
    }
};