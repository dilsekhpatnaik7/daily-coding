// Problem Link: https://practice.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0?problemType=functional&difficulty[]=-1&page=1&query=problemTypefunctionaldifficulty[]-1page1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-all-factorial-numbers-less-than-or-equal-to-n

class Solution {
public:
    vector<long long> factorialNumbers(long long N) {
        vector<long long> ans;
        long long counter = 2, factorial = 1;
        while(factorial <= N) {
            ans.push_back(factorial);
            factorial *= counter;
            counter++;
        }
        return ans;
    }
};