// Problem Link: https://practice.geeksforgeeks.org/problems/1fc4278adf2a36780f637c7b4cd06391dd1487e4/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    int minVal(int a, int b) {
        int cntbit = 0;
        for(int i = 0; i < 32; i++){
            if(b & 1 << i)
              cntbit++;
        }
        int ans = 0;
        for(int i = 31; i >= 0 && cntbit > 0; i--){
           if(a & 1 << i){
               ans = ans | 1 << i;
               cntbit--;
           }
        }
        for(int i = 0; i < 32 && cntbit > 0; i++){
               if(!(ans & 1 << i)){
                   cntbit--;
                   ans = ans | 1 << i;
               }
        }
       return ans;
    }
};