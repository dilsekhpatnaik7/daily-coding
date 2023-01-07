// Problem Link: https://practice.geeksforgeeks.org/problems/af49b143a4ead583e943ca6176fbd7ea55b121ae/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        sort(start, start + N);
        sort(end, end + N);
        int total = 1;
        for(int i = 1, j = 0; i < N && j < N; i++){
            if(end[j] - start[i] > 0) total++;
            else j++;
        }
        return total;
    }
};