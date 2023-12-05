// Problem Link: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=row-with-max-1s
//As all the rows are sorted, we use binary search.
class Solution {
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = -1;
	    int i = 0, j = m - 1;
	    while(i < n && j >= 0) {
	        if(arr[i][j] == 1) {
	            ans = i;
	            j--;
	        }
	        else i++;
	    }
	    return ans;
	}

};