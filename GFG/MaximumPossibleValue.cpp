// Problem Link: https://practice.geeksforgeeks.org/problems/2d3fc3651507fc0c6bd1fa43861e0d1c43d4b8a1/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        long long ans = 0, t = 0, z = 0, n = A.size();
        for(int i = 0; i < N; i++) B[i] /= 2;
        int x = INT_MAX;
        for(int i = 0; i < N; i++) {
            if(B[i]) x = min(A[i], x);
            t += B[i] * A[i];
            z += B[i];
        }
        if(z % 2) t -= x;
        return t * 2;
    }
};