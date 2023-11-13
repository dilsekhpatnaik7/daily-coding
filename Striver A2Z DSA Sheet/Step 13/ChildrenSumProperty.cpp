/*
Problem Link: https://www.codingninjas.com/studio/problems/children-sum-property_8357239?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(Height of Tree)
*/

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/
int solve(Node* root) {
    if(!root) return 1;
    if(!root->left && !root->right) return 1;
    
    int sum = 0;
    if(root->right) sum += root->right->data;
    if(root->left) sum += root->left->data;
    
    return sum == root->data && solve(root->left) && solve(root->right);
}

bool isParentSum(Node *root){
    if(!root) return 1;
        
    return solve(root);
}