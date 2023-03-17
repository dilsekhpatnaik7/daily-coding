// Problem Link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?category[]=Hash&category[]=Hash&company[]=Amazon&company[]=Amazon&page=1&query=category[]Hashcompany[]Amazonpage1company[]Amazoncategory[]Hash&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-subarray-with-0-sum

class Solution{
public:
    int maxLen(vector<int>&A, int n) {
        unordered_map<int,int> mp;
        int sum = 0, maximum = 0;
        for(int i = 0; i < n; i++) {
            sum += A[i];
            if(sum == 0) {
                maximum = max(maximum, i+1);
            }
            else if(mp.find(sum) != mp.end()) {
               maximum = max(maximum, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }
        return maximum; 
    }
};