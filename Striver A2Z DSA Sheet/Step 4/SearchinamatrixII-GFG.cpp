/*
Problem Link: https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

Time Complexity: O(log (M * N))
Space Cmplexity: O(1)
*/

class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X) {
	    int i = 0, j = M - 1;
	    while(i < N && j >=0) {
	        if(mat[i][j] == X) return 1;
	        else if(X > mat[i][j]) i++;
	        else j--;
	    }
	    return 0;
	}
};