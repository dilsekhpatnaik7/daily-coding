// Problem Link: https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=overlapping_intervals

class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size() == 0) return ans;
        
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1], n = intervals.size();
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] <= end) end = max(end, intervals[i][1]);
            else {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};