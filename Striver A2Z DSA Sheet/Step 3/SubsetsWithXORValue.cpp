// Problem Link: https://practice.geeksforgeeks.org/problems/subsets-with-xor-value2023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=subsets-with-xor-value

class Solution{
public:
    int recursion(int index, int prefixXOR, int K, vector<int>&arr) {
        if(index == arr.size() && prefixXOR == K)return 1;
        else if(index == arr.size()) return 0;
            
        int pick = recursion(index + 1, prefixXOR ^ arr[index], K, arr);
        int notpick = recursion(index + 1, prefixXOR, K, arr);
        return pick + notpick;
    }

    int subsetXOR(vector<int> arr, int N, int K) {
        int prefixXOR = 0;
        return recursion(0, prefixXOR, K, arr);
    }
};