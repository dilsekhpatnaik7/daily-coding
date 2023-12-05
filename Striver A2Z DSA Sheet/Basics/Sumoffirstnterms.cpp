// Problem Link: https://practice.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sum-of-first-n-terms

class Solution {
public:
    long long sendCube(long long n) {
        return n * n * n;
    }
    long long sumOfSeries(long long N) {
        long long i = 1, ans = 0;
        while(i <= N) {
            ans += sendCube(i);
            i++;
        }
        return ans;
    }
};