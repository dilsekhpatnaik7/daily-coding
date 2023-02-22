// Problem Link: https://practice.geeksforgeeks.org/problems/95423710beef46bd66f8dbb48c510b2c320dab05/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

/* struct Node {
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};*/

class Solution{
    public:
    void connect(Node *root) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
           int qsize=q.size();
           while(qsize--) {
               auto node = q.front();
               q.pop();
               if(qsize>0) node->nextRight = q.front();
               if(node->left) q.push(node->left);
               if(node->right) q.push(node->right);
           }
       }
    }    
};