// Problem Link: https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k

class Solution {
public:
    int lenOfLongSubarr(int A[],  int N, int K) { 
        unordered_map<int, int> map;
        map[0] = -1;
        int sum = 0, count = 0;
        for(int i = 0; i < N; i++) {
            sum += A[i];
            if(sum == K) count = max(count, i + 1);
            if(map.find(sum - K) != map.end()) count = max(count, i - map[sum - K]);
            if(map.find(sum) == map.end()) map.insert({sum, i});
        }
        return count;
    } 
};