// Problem Link: https://leetcode.com/problems/number-of-good-paths/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class DSU {
private:
	vector<int> parent;
public:
	DSU(int n) {
		parent.resize(n);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int x){
		if (parent[x] == x)
			return x;
		parent[x] = find(parent[x]);
		return parent[x];
	}
	void unions(int x, int y){
		int x_par = find(x);
		int y_par = find(y);
		if (x_par == y_par)
			return;
		parent[y_par] = x_par;
	}
};

class Solution {
public:
	int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        //Step 1:
        sort(begin(edges), end(edges),
		     [&](vector<int>& a, vector<int>& b)
		{
			return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]);
		});
        //Step 2:
		int n = vals.size();
		int ans = n;
		DSU ufobj(n);
        //Step 3:
		vector<unordered_map<int, int>> freq(n); // freq[parent_in_unionFind][value]
        for (int i = 0; i < n; ++i)
			freq[i][vals[i]] = 1;
        //Step 4:
		int maxe, u, v, uParent, vParent;
		for (vector<int>& curr : edges)
		{
            u = curr[0]; v = curr[1];
			maxe = max(vals[u], vals[v]);
			uParent = ufobj.find(u);
			vParent = ufobj.find(v);
			ufobj.unions(u, v);
			ans += freq[uParent][maxe] * freq[vParent][maxe];
			freq[uParent][maxe] += freq[vParent][maxe];
            freq[vParent].erase(maxe);
		}
        //Step 5:
		return ans;
	}
};