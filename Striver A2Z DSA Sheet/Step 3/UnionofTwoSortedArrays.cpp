// Problem Link: https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=union-of-two-sorted-arrays

// 1st Approach
class Solution{
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        vector<int> ans;
        set<int> s;
        for(int i = 0; i < n; i++) {
            s.insert(arr1[i]);
        }
        for(int i = 0; i < m; i++) {
            s.insert(arr2[i]);
        }
        for(auto x: s) {
            ans.push_back(x);
        }
        return ans;
    }
};

// 2nd Approach
class Solution{
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        vector<int> ans;
        unordered_map<int> map;
        for(int i = 0; i < n; i++) {
            map[arr1[i]]++;
        }
        for(int i = 0; i < m; i++) {
            map[arr2[i]]++;
        }
        for(auto x: map) {
            ans.push_back(x.first);
        }
        return ans;
    }
};