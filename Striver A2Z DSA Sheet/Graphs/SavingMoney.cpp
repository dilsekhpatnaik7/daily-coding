/*
Problem Link: https://www.codingninjas.com/studio/problems/saving-money_1171195?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(E)
Space Complexity: O(N)
*/

int savingMoney(int n, int source, int destination, int K, vector<vector<int>> &trains) {
    vector<pair<int, int>> adj[n];
    for(auto i: trains) {
        adj[i[0]].push_back({i[1], i[2]});
    }

    vector<int> dist(n, 1e9);
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {source, 0}});
    dist[source] = 0;
    
    while(!q.empty()) {
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        
        if(stops > K) continue;
        for(auto i: adj[node]) {
            int adjacentNode = i.first;
            int weight = i.second;
            
            if(cost + weight < dist[adjacentNode] && stops <= K) {
                dist[adjacentNode] = cost + weight;
                q.push({stops + 1, {adjacentNode, cost + weight}});
            }
        }
    }
    return dist[destination] == 1e9 ? -1 : dist[destination];
}