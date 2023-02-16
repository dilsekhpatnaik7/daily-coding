// Problem Link: https://practice.geeksforgeeks.org/problems/print-gfg-n-times/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-gfg-n-times

class Solution {
  public:
    void printGfg(int N) {
        if(N == 0) return;
        cout << "GFG ";
        printGfg(N - 1);
    }
};