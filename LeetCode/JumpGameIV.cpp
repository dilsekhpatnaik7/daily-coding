// Problem Link: https://leetcode.com/problems/jump-game-iv/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)  return 0;
        unordered_map<int, vector<int>> indices;
        for(int i = 0; i < n; i++) {
            indices[arr[i]].push_back(i);
        }

        queue<int> storeIndex;
        vector<bool> visited(n);
        storeIndex.push(0);
        visited[0] = true;
        int steps = 0;
        while(!storeIndex.empty()) {
            int size = storeIndex.size();
            while(size--) {
                int currIndex = storeIndex.front();
                storeIndex.pop();
                if(currIndex == n - 1) return steps;

                vector<int>& jumpNextIndices = indices[arr[currIndex]];
                jumpNextIndices.push_back(currIndex - 1);
                jumpNextIndices.push_back(currIndex + 1);
                for(int jumpNextIndex : jumpNextIndices) {
                    if(jumpNextIndex >= 0 && jumpNextIndex < n && !visited[jumpNextIndex]) {
                        storeIndex.push(jumpNextIndex);
                        visited[jumpNextIndex] = true;
                    }
                }
                jumpNextIndices.clear();
            }
            steps++;
        }
        return -1;
    }
};