// Problem Link: https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-first-n-fibonacci-numbers

class Solution {
public:
    vector<long long> printFibb(int n)  {
        vector<long long> ans(n, -1);
        ans[0] = 1;
        ans[1] = 1;
        int i = 2;
        while(i < n) {
            ans[i] = ans[i - 1] + ans[i - 2];
            i++;
        }
        return ans;
    }
};