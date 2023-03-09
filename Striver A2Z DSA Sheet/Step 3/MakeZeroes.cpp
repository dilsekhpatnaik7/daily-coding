// Problem Link: https://practice.geeksforgeeks.org/problems/make-zeroes4042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=make-zeroes

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        vector<vector<int>> temp = matrix;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(temp[i][j] == 0) {
                    if(i - 1 >= 0) {
                        matrix[i][j] += temp[i - 1][j];
                        matrix[i - 1][j] = 0;
                    }
                    if(i + 1 < matrix.size()) {
                        matrix[i][j] += temp[i + 1][j];
                        matrix[i + 1][j] = 0;
                    }
                    if(j - 1 >= 0) {
                        matrix[i][j] += temp[i][j - 1];
                        matrix[i][j - 1] = 0;
                    }
                    if(j + 1 < matrix[0].size()) {
                        matrix[i][j] += temp[i][j + 1];
                        matrix[i][j + 1] = 0;
                    }
                }
            }
        }
    }
};