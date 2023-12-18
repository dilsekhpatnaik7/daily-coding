/*
Problem Link: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

Time Complexity: O(E)
Space Complexity: O(N)
*/

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        int mod = 100000;
        
        while(!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(node == end) return steps;
            
            for(auto i: arr) {
                int nextNum = (node * i) % mod;
                if(steps + 1 < dist[nextNum]) {
                    dist[nextNum] = steps + 1;
                    q.push({nextNum, steps + 1});
                }
            }
        }
        return -1;
    }
};