// Problem Link: https://practice.geeksforgeeks.org/problems/reverse-bits3556/1

class Solution {
  public:
    long long reversedBits(long long X) {
        string str = bitset<32>(X).to_string();
        reverse(str.begin(), str.end());
        long long ans = bitset<32>(str).to_ulong();
        return ans;
    }
};