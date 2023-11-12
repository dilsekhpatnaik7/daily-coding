/*
Problem Link: https://www.codingninjas.com/studio/problems/all-root-to-leaf-paths-in-binary-tree._983599?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(Height of Tree)
*/

/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        int data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
********************************************************************/
bool isLeaf(BinaryTreeNode<int> * root) {
    return root && (!root->left && !root->right);
}

void solve(BinaryTreeNode<int> * root, string s, vector<string>& ans) {
    if(!root) return;

    string t = to_string(root->data);
    if(isLeaf(root)) {
        ans.push_back(s + t);
        return;
    }

    if(root->left) solve(root->left, s + t + " ", ans);
    if(root->right) solve(root->right, s + t + " ", ans);
}

vector<string> allRootToLeaf(BinaryTreeNode<int> * root) {
    if(!root) return {};

    vector<string> ans;
    solve(root, "", ans);
    return ans;
}