// Problem Link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-missing-and-repeating

// Brute Force Solution
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        map<int,int> map;
        vector <int> v;
        for(int i = 0; i < n; i++) map[arr[i]]++;
            
        for(auto it = map.begin(); it != map.end(); it++) {
            if((it->second) == 2)
             v.push_back(it->first);
        }
        for(int i = 1; i <= n; i++) {
            if(map.find(i) == map.end())
                v.push_back(i);
        }
        return v;
    }
};

// Optimal Solution Using Mathematics
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int SN = (n * (n + 1)) / 2;
        int S2N = (n * (n + 1) * (2 * n + 1)) / 6;
        int S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
        	S += arr[i];
        	S2 += (long long)arr[i] * (long long)arr[i];
        }
        long long val1 = S - SN;
        long long val2 = S2 - S2N;
        val2 = val2 / val1;
        int repeating = (val1 + val2) / 2;
        int missing = repeating - val1;
        return {repeating, missing};
    }
};