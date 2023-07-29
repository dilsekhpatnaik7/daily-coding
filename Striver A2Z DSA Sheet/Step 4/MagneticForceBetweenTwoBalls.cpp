/*
Problem Link: https://leetcode.com/problems/magnetic-force-between-two-balls/

Time Complexity: O(N * log(N))
Space Cmplexity: O(1)
*/

class Solution {
public:
    bool canWePlace(vector<int>& position, int distance, int m) {
        int countBalls = 1, last = position[0], n = position.size();
        for(int i = 1; i < n; i++) {
            if(position[i] - last >= distance) {
                countBalls++;
                last = position[i];
            }
            if(countBalls >= m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        
        int low = 0, high = position[n - 1] - position[0];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canWePlace(position, mid, m)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};