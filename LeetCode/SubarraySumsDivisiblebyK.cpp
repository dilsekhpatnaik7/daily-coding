// Problem Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int> m;
        m[0]++;
        for(auto i: nums){
           sum += i;
           if(m[(sum % k + k) % k] > 0) count += m[(sum % k + k) % k];
           m[(sum % k + k) % k]++;
        }
        return count;
    }
};