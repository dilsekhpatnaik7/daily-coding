// Problem Link: https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {\
    unordered_map<int, int> map;
    int count = 0, xorAns = 0, n = A.size();
    for(int i = 0; i < n; i++) {
        xorAns ^= A[i];
        if(xorAns == B) count++;
        if(map.find(xorAns ^ B) != map.end()) count += map[xorAns ^ B];
        map[xorAns]++;
    }
    return count;
}