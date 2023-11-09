/*
Problem Link: https://www.codingninjas.com/studio/problems/check-identical-trees_799364?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
		
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/
 bool solve(BinaryTreeNode<int>* p, BinaryTreeNode<int>* q) {
    if(!p || !q) return p == q;

    return (p->data == q->data) && solve(p->left, q->left) && solve(p->right, q->right);
}

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    return solve(root1, root2);
}