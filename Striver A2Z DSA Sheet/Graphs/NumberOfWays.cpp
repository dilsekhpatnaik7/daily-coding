/*
Problem Link: https://www.codingninjas.com/studio/problems/number-of-ways_8360639?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(E*log(V))
Space Complexity: O(N)
*/

int mod = 1e9 + 7;
int numberOfWays(int n, int m, vector<vector<int>> edges) {
    vector<pair<int, int>> adj[n];
    for(auto i: edges) {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }
    
    vector<long long> dist(n, 1e18);
    vector<long long> ways(n, 0);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
    q.push({0, 0});
    dist[0] = 0;
    ways[0] = 1;

    while(!q.empty()) {
        long long time = q.top().first;
        long long node = q.top().second;
        q.pop();


        for(auto i: adj[node]) {
            long long adjacentNode = i.first;
            long long nextTime = i.second;

            if(time + nextTime < dist[adjacentNode]) {
                dist[adjacentNode] = time + nextTime;
                q.push({time + nextTime, adjacentNode});

                ways[adjacentNode] = ways[node];
            } else if(time + nextTime == dist[adjacentNode]) {
                ways[adjacentNode] = (ways[adjacentNode] + ways[node]) % mod;
            }
        }
    }
    return (int)ways[n - 1] % mod;
}