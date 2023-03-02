// Problem Link: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/0?problemType=functional&page=1&query=problemTypefunctionalpage1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-consecutive-subsequence

class Solution {
public:
    int findLongestConseqSubseq(int arr[], int N) {
        int longestStreak = 0;
        unordered_set<int> hashSet;
        for(int i = 0; i < N; i++) {
            hashSet.insert(arr[i]);
        }
        
        for(int i = 0; i < N; i++) {
            if(!hashSet.count(arr[i] - 1)) {
                int currentNumber = arr[i];
                int currentStreak = 1;
                while(hashSet.count(currentNumber + 1)) {
                    currentNumber++;
                    currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};