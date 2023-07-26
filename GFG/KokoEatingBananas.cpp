// Problem Link: https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int findMax(vector<int>& piles) {
        int maximum = INT_MIN, n = piles.size();
        for(int i = 0; i < n ; i++) {
            maximum = max(maximum, piles[i]);
        }
        return maximum;
    }

    bool calculateTotalHours(vector<int>& piles, long long mid, int h) {
        if(mid == 0) return 0;
        long long totalHours = 0;
        long long n = piles.size();
        for(int i = 0; i < n; i++) {
            totalHours += (piles[i] + mid - 1) / mid;
            if(totalHours > h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 0, high = findMax(piles);
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            bool totalHours = calculateTotalHours(piles, mid, h);
            if(totalHours) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};