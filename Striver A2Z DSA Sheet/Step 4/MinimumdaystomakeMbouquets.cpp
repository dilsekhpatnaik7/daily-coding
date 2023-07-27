// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1

class Solution {
  public:
    bool isPossible(vector<int>& bloomDay, long long day, int M, int K) {
        int count = 0, noOfBouquet = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= day) count++;
            else {
                noOfBouquet += (count / K);
                count = 0;
            }
        }
        noOfBouquet += (count / K);
        return noOfBouquet >= M;
    }
    
    int solve(int M, int K, vector<int> &bloomDay){
        if(((long long)M * (long long)K) > bloomDay.size()) return - 1;
        int minimum = INT_MAX, maximum = INT_MIN;
        for(int i = 0; i < bloomDay.size(); i++) {
            minimum = min(minimum, bloomDay[i]);
            maximum = max(maximum, bloomDay[i]);
        }

        int low = minimum, high = maximum;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(isPossible(bloomDay, mid, M , K)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};