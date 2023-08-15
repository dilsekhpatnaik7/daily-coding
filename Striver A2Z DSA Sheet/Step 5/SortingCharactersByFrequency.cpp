/*
Problem Link: https://leetcode.com/problems/sort-characters-by-frequency/

Time Complexity: O(N * log(N))
Space Cmplexity: O(N)
*/

class Solution {
public:
    static bool comp(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        if(!s.length()) return "";
        vector<pair<char, int>> v;
        unordered_map<char,int> map;
        for(int i = 0; i < s.length(); i++) {
            map[s[i]]++;
        }
        for(auto x: map) {
            v.push_back({x.first, x.second});
        }
        sort(v.begin(), v.end(), comp);
        string ans = "";
        for(auto x: v) {
            for(int i = 0; i < x.second; i++) {
                ans += x.first;
            }
        }
        return ans;
    }
};