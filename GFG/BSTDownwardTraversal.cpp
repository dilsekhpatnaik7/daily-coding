// Problem Link: https://practice.geeksforgeeks.org/problems/c85e3a573a7de6dfd18398def16d05387852b319/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
public:
    long long int ans= 0;
    Node *find(Node *root , int target) {
        if(root == NULL)
            return NULL;
        
        if(root->data == target) {
            return root;
        }
        
        if(root->data > target) {
            return find(root->left , target);
        }
        else if(root->data < target) {
            return find(root->right , target);
        }
    }
    
    void solve(Node *root , int c) {
        if(root == NULL) {
          return ;
        }
      
        if(c == 0) {
          ans += root->data;
        }
        solve(root->left , c-1);
        solve(root->right , c+1);
    }
    
    long long int verticallyDownBST(Node *root,int target) {
       Node *tar = find(root , target);
       if(tar == NULL) return -1;
       
       solve(tar , 0);
       return ans - tar->data;
    }
};