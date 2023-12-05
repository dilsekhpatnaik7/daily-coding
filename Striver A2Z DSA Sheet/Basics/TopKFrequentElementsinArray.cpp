// Problem Link: https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1

class Solution {
  public:
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
    vector<int> topK(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        vector<pair<int, int>> v;
        for(auto i: m) {
            v.push_back(make_pair(i.first, i.second));
        }
        sort(begin(v), end(v), comp);
        vector<int> ans;
        int i = 0;
        while(i < k) {
            ans.push_back(v[i].first);
            i++;
        }
        return ans;
    }
};