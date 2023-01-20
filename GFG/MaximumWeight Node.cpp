// Problem Link: https://practice.geeksforgeeks.org/problems/b64485d3994958cca8748991bb58668204b3e4c0/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
  int maxWeightCell(int N, vector<int> Edge) {
       vector<int>weight(N,0);
       for(int i = 0; i < N; i++){
            if(Edge[i] != -1)
                weight[Edge[i]] += i;
       }
       int mx = INT_MIN;
       int ans = 0;
       for(int i = 0; i < N; i++){
            if(weight[i] >= mx){
                ans = i;
                mx = weight[i];
            }
       }
       return ans;
    }
};