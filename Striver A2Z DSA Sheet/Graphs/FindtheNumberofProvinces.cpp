/*
Problem Link: https://www.codingninjas.com/studio/problems/find-the-number-of-states_1377943?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(V+E)
Space Complexity: O(V)
*/

void solve(vector<vector<int>>& roads, int i, vector<int>& vis) {
    vis[i] = 1;
    for(int j = 0; j < roads.size(); j++) {
        if(roads[i][j] && !vis[j]) solve(roads, j, vis);
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    if(!n) return 0;

    int provinces = 0;
    vector<int> vis(n);
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            solve(roads, i, vis);
            provinces++;
        }
    }
    return provinces;
}