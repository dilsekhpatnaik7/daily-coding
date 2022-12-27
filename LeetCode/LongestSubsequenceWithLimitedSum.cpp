// Problem Link: https://leetcode.com/problems/longest-subsequence-with-limited-sum/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end()); 
        vector<int> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++){
            int query = queries[i];
            ans.push_back(upper_bound(prefix.begin(), prefix.end(), query) - prefix.begin());
        }
        return ans;
    }
};