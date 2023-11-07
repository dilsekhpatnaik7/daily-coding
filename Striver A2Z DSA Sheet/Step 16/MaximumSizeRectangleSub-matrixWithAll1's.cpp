/*
Problem Link: https://www.codingninjas.com/studio/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
int largestRectangleArea(vector<int>& histo) {
	stack<int> st;
	int maxA = 0;
	int n = histo.size();
	for(int i = 0; i <= n; i++) {
		while(!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
			int height = histo[st.top()];
			st.pop();
			int width;
			if(st.empty()) width = i;
			else width = i - st.top() - 1;
			maxA = max(maxA, width * height);
		}
		st.push(i);
	}
	return maxA;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	int maximum = 0;

	vector<int> heights(m, 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(mat[i][j] == 1) heights[j]++;
			else heights[j] = 0;
		}

		int area = largestRectangleArea(heights);
		maximum = max(maximum, area);
	}
	return maximum;
}