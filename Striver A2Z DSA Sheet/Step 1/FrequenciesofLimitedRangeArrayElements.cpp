// Problem Link: https://practice.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0

class Solution{
public:
    void frequencyCount(vector<int>& arr,int N, int P) {
        map<int, int> m;
        for(int i = 1; i <= N; i++) m[arr[i - 1]]++;
        for(int i = 1; i <= N; i++) arr[i - 1] = m[i];
    }
};