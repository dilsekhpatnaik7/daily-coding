/*
Problem Link: https://leetcode.com/problems/string-to-integer-atoi/

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length(), i = 0;
        while(i < n && s[i] == ' ') i++;
        int positive = 0, negative = 0;
        if(s[i] == '+') {
            positive++;
            i++;
        }
        if(s[i] == '-') {
            negative++;
            i++;
        }
        double ans = 0;
        while(i < n && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
            i++;
        }
        if(negative > 0) ans = -1 * ans;
        if(positive > 0 && negative > 0) return 0;
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        
        return (int)ans;
    }
};