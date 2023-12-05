/*
Problem Link: https://leetcode.com/problems/maximal-rectangle/description/

Time Complexity: O(N*M)
Space Complexity: O(N)
*/

class Solution {
public:
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), maximum = 0;

        vector<int> heights(m, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }

            int area = largestRectangleArea(heights);
            maximum = max(maximum, area);
        }
        return maximum;
    }
};