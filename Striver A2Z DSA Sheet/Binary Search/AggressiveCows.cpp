/*
Problem Link: https://www.codingninjas.com/studio/problems/aggressive-cows_1082559?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N * log(N))
Space Cmplexity: O(1)
*/

bool canWePlace(vector<int>& stalls, int distance, int cows) {
    int countCows = 1, last = stalls[0], n = stalls.size();
    for(int i = 1; i < n; i++) {
        if(stalls[i] - last >= distance) {
            countCows++;
            last = stalls[i];
        }
        if(countCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    
    int low = 0, high = stalls[n - 1] - stalls[0];
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canWePlace(stalls, mid, k)) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}