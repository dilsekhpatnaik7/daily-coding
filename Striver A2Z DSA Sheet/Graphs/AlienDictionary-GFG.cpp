/*
Problem Link: https://www.geeksforgeeks.org/problems/alien-dictionary/1

Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

class Solution{
    public:
    vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> indegree(V, 0);
	    for(int i = 0; i < V; i++) {
	        for(auto adjacentNode: adj[i]) {
	            indegree[adjacentNode]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    vector<int> ans;
	    while(!q.empty()) {
	        int node = q.front(); q.pop();
	        ans.push_back(node);
	        
	        for(auto adjacentNode: adj[node]) {
	            indegree[adjacentNode]--;
	            if(indegree[adjacentNode] == 0) q.push(adjacentNode);
	        }
	    }
	    
	    return ans;
	}
    
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i = 0; i < N - 1; i++) {
            string s1 = dict[i], s2 = dict[i + 1];
            int l = min(s1.size(), s2.size());
            for(int j = 0; j < l; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for(auto i: topo) ans += char(i + 'a');
        
        return ans;
    }
};