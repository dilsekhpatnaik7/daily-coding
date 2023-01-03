// Problem Link: https://practice.geeksforgeeks.org/problems/7d0fa4007b8eabadc404fcc9fa917aa52982aa96/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    int removeStudents(int H[], int N) {
        vector<int> a;
        for(int i = 0; i < N; i++){
            int it = lower_bound(a.begin(), a.end(), H[i]) - a.begin();
            if(it == a.size()){
                a.push_back(H[i]);
            }
            else{
                a[it] = H[i];
            }
        }
        return N - a.size();
    }
};