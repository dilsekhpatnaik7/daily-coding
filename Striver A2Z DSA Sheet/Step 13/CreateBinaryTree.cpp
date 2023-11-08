/*
Problem Link: https://www.codingninjas.com/studio/problems/create-binary-tree_8360671?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

Node *constructTree(int index, vector<int>& arr){
    if(index > arr.size() - 1) return NULL;

    Node *root = new Node(arr[index]);
    root->left = constructTree(index*2 + 1, arr);
    root->right = constructTree(index*2 + 2, arr);

    return root;
}

Node* createTree(vector<int>&arr){
    Node* root = constructTree(0, arr);
    return root;
}