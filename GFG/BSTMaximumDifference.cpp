// Problem Link: https://practice.geeksforgeeks.org/problems/e841e10213ddf839d51c2909f1808632a19ae0bf/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    Node* f(Node* root, int target, int& uppersum) {
        if(root == NULL) return NULL;
        if(root->data == target) return root;
        uppersum += root->data;
        if(root->data > target) return f(root->left, target, uppersum);
        if(root->data < target) return f(root->right, target, uppersum);
        return NULL;
    }
    
    void MinSum(Node* root, int& mini, int lowersum) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            lowersum += root->data;
            mini= min(mini, lowersum);
        }
        lowersum += root->data;
        MinSum(root->left, mini, lowersum);
        MinSum(root->right, mini, lowersum);
    }
    
    int maxDifferenceBST(Node *root, int target){
        int uppersum = 0;
        Node* tarRoot = f(root, target, uppersum);
        if(!tarRoot) return -1;
        
        int mini = 1e9;
        MinSum(tarRoot, mini, 0);
        mini -= target;
        return uppersum - mini;
    }
};