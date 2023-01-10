// Problem Link: https://practice.geeksforgeeks.org/problems/d7e0ce338b11f0be36877d9c35cc8dfad6636957/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    void toSumTree(Node *node) {
        if(node){
            if(!node->left and !node->right){
                node->data = 0;
                return;
            }
            int sum = 0;
            if(node->left){
                sum += node->left->data;
                toSumTree(node->left);
                sum += node->left->data;
            }
            if(node->right){
                sum += node->right->data;
                toSumTree(node->right);
                sum += node->right->data;
            }
            node->data = sum;
        }
    }
};