/*
Problem Link: https://www.codingninjas.com/studio/problems/alien-dictionary_630423?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

#include<bits/stdc++.h>
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

string getAlienLanguage(vector<string> &dictionary, int k) {
    vector<int> adj[k];
    int n = dictionary.size();
    for(int i = 0; i < n - 1; i++) {
        string s1 = dictionary[i], s2 = dictionary[i + 1];
        int l = min(s1.size(), s2.size());
        for(int j = 0; j < l; j++) {
            if(s1[j] != s2[j]) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }
    
    vector<int> topo = topoSort(k, adj);
    string ans = "";
    for(auto i: topo) ans += char(i + 'a');
    
    return ans;
}