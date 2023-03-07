// Problem Link: https://leetcode.com/problems/minimum-time-to-complete-trips/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    long long int numberOfTripsForGivenTime(vector<int>&a , long long int givenTime) {
        long long int totalTrips = 0;
        for(auto x : a) {
            long long int val = x;
            totalTrips += (givenTime / val);
        }
        return totalTrips;
    }
    long long minimumTime(vector<int>& arr ,  int totalTrips) {
        long long int lowestTime = 1;
        long long int highestTime = 1e14;
        while(lowestTime < highestTime) {
            long long int mid = lowestTime + (highestTime - lowestTime) / 2;
            if(numberOfTripsForGivenTime(arr , mid) >= totalTrips) highestTime = mid;
            else lowestTime = mid + 1;
        }
        return lowestTime;
    }
};