// Problem Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    bool isPossible(vector<int>& bloomDay, long long day, int m, int k) {
        int count = 0, noOfBouquet = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= day) count++;
            else {
                noOfBouquet += (count / k);
                count = 0;
            }
        }
        noOfBouquet += (count / k);
        return noOfBouquet >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(((long long)m * (long long)k) > bloomDay.size()) return - 1;
        int minimum = INT_MAX, maximum = INT_MIN;
        for(int i = 0; i < bloomDay.size(); i++) {
            minimum = min(minimum, bloomDay[i]);
            maximum = max(maximum, bloomDay[i]);
        }

        int low = minimum, high = maximum;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(isPossible(bloomDay, mid, m , k)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};