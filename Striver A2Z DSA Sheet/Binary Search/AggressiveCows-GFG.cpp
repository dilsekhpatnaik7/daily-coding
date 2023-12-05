/*
Problem Link: https://practice.geeksforgeeks.org/problems/aggressive-cows/0

Time Complexity: O(N * log(N))
Space Cmplexity: O(1)
*/

class Solution {
public:
    bool canWePlace(vector<int>& stalls, int distance, int cows) {
        int countCows = 1, last = stalls[0], n = stalls.size();
        for(int i = 1; i < n; i++) {
            if(stalls[i] - last >= distance) {
                countCows++;
                last = stalls[i];
            }
            if(countCows >= cows) return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        
        int low = 0, high = stalls[n - 1] - stalls[0];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canWePlace(stalls, mid, k)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};