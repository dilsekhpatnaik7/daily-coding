// Problem Link: https://practice.geeksforgeeks.org/problems/6eb51dc638ee1b936f38d1ab4b2f7062d4425463/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        
        return gcd(b, a % b);
    }
    
    int solve(Node* root, int& res, int& maxi) {
        if(root == NULL) return -1;
        
        int left_ = solve(root->left, res, maxi);
        int right_ = solve(root->right, res, maxi);
        
        int gcd_ = gcd(left_, right_);
        
        if((left_ != -1) && (right_ != -1) && (gcd_ > maxi)) {
            maxi = gcd_;
            res = root->data;
        }
        return root->data;
    }

    int maxGCD( Node* root) {
        if(root == NULL) return 0;
        int res = 0, maxi = 0;
        solve(root, res, maxi);
        
        return res;
    }
};