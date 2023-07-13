// Problem Link: https://leetcode.com/problems/sqrtx/

class Solution {
public:
    long long binarySearch(int x) {
        int low = 0, high = x, ans = -1;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            long long square = mid * mid;
            if(square == (long long)(x)) return mid;
            
            if(square < (long long)(x)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    int mySqrt(int x) {
        return binarySearch(x);
    }
};