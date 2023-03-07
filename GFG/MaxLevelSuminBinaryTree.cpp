// Problem Link: https://practice.geeksforgeeks.org/problems/4b7ff87c26ed23b3f63c25c611690213d44fb6aa/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

/*
struct Node {
    int data;
    Node* left, *right;
}; 
*/
class Solution{
public:
    int maxLevelSum(Node* root) {
        queue<Node*> q;
        q.push(root);
        int ans = INT_MIN;
        while(!q.empty()) {
            int size = q.size();
            int currentLevelSum = 0;
            while(size--) {
                Node* temp = q.front();
                q.pop();
                currentLevelSum += temp->data;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans = max(ans, currentLevelSum);
        }
        return ans;
    }
};