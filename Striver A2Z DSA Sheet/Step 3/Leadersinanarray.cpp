// Problem Link: https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array

class Solution {
public:
    vector<int> leaders(int a[], int n) {
        int maximum = a[n - 1];
        vector<int> ans;
        ans.push_back(maximum);
        for(int i = n - 2; i >= 0; i--) {
            if(a[i] >= maximum) {
                maximum = a[i];
                ans.push_back(a[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};