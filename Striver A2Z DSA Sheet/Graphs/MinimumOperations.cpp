/*
Problem Link: https://www.codingninjas.com/studio/problems/minimum-operations_8360665?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(E)
Space Complexity: O(N)
*/

int minimumOperations(int n, int start, int end, vector<int> &a) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    vector<int> dist(1000, 1e9);
    dist[start] = 0;
    int mod = 1000;
    
    while(!q.empty()) {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        if(node == end) return steps;
        
        for(auto i: a) {
            int nextNum = (node * i) % mod;
            if(steps + 1 < dist[nextNum]) {
                dist[nextNum] = steps + 1;
                q.push({nextNum, steps + 1});
            }
        }
    }
    return -1;
}