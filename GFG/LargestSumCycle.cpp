// Problem Link: https://practice.geeksforgeeks.org/problems/51afa710a708c0681748445b509696dd588d5c40/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    long long largestcycle = -1;
    void DFS(int node, vector<int> &Edge, bool visited[], bool pathvisited[]) {
        visited[node] = true;
        pathvisited[node] = true;

        if (Edge[node] != -1) {
            int adj = Edge[node];
            if (!visited[adj]) {
                DFS(adj, Edge, visited, pathvisited);
            }
            else if (pathvisited[adj]) {
                int curr = adj;
                long long sum = 0;
                do {
                    sum += curr;
                    curr = Edge[curr];
                } while (curr != adj);
                largestcycle = max(largestcycle, sum);
            }
        }

        pathvisited[node] = false;
    }
    long long largestSumCycle(int N, vector<int> Edge) {
        bool visited[N] = {0};
        bool pathvisited[N] = {0};
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                DFS(i, Edge, visited, pathvisited);
            }
        }
        return largestcycle;
    }
};