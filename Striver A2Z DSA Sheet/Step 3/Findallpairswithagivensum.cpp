// Problem Link: https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-all-pairs-whose-sum-is-x

class Solution{
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    }
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X) {
        vector<pair<int, int>> ans;
        unordered_map<int, int> map;
        for(int i = 0; i < N; i++) {
            map[A[i]]++;
        }
        for(int i = 0; i < M; i++) {
            if(map.find(X - B[i]) != map.end()) {
                ans.push_back({X - B[i], B[i]});
            }
        }
        sort(ans.begin(), ans.end(), comp);
        return ans;
    }
};