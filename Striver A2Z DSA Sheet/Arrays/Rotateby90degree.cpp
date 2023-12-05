// Problem Link: https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotate-by-90-degree

// GFG Version Anti-Clockwise Rotation
class Solution {   
public:
    void rotateby90(vector<vector<int> >& matrix, int n) {
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        reverse(matrix.begin(), matrix.end());
    } 
};