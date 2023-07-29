/*
Problem Link: https://www.spoj.com/problems/AGGRCOW/

Time Complexity: O(No.OfTestCases * Size) + O(Size * log(Size))
Space Cmplexity: O(Size)
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool canWePlace(vector<long long>& stalls, long long distance, long long cows) {
    long long countCows = 1, last = stalls[0], n = stalls.size();
    for(long long i = 1; i < n; i++) {
        if(stalls[i] - last >= distance) {
            countCows++;
            last = stalls[i];
        }
        if(countCows >= cows) return true;
    }
    return false;
}

int binarySearch(vector<long long> &stalls, long long n, long long k) {
        sort(stalls.begin(), stalls.end());
        
        long long low = 0, high = stalls[n - 1] - stalls[0];
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(canWePlace(stalls, mid, k)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }

int solve() {
	long long n, cows; 
	cin >> n >> cows;
	vector<long long> stalls;
	for(long long i = 0; i < n; i++) {
		long long t;
		cin >> t;
		stalls.push_back(t);
	}
	
	return binarySearch(stalls, n, cows);
}

int main() {
	long long t; cin >> t;
	while(t--) {
		cout << solve() << endl;;
	}
	return 0;
}