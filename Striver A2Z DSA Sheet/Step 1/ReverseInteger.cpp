// Problem Link: https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x) {
            int digit = x % 10;
            if (ans > (INT_MAX / 10 - digit / 10) || ans < (INT_MIN / 10 - digit / 10)) {
                return 0;
            }
            ans *= 10;
            ans += digit;
            x /= 10;
        }
        return ans;
    }
};