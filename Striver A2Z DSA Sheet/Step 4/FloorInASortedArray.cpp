// Problem Link: https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%3BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-arrayhttps://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%3BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-array


class Solution{
public:
    int findFloor(vector<long long> v, long long n, long long x){
        long long low = 0, high = n - 1, ans = -1;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(v[mid] == x) return mid;
            else if(v[mid] < x) {
                low = mid + 1;
                ans = mid;
            }
            else high = mid - 1;
        }
        return ans != -1 ? ans : -1;
    }
};