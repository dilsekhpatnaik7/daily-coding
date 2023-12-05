/*
Problem Link: https://leetcode.com/problems/fibonacci-number/description/

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int solve(int n) {
        if(n <= 1) return n;
        return solve(n - 1) + solve(n - 2);
    }

    int fib(int n) {
        return solve(n);
    }
};