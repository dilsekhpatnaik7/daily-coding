/*
Problem Link: https://practice.geeksforgeeks.org/problems/count-number-of-nodes-in-a-binary-tree/1?page=1&sortBy=accuracy&query=page1sortByaccuracy

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
  public:
    int findLeftHeight(Node* root) {
        int height = 0;
        while(root) {
            height++;
            root = root->left;
        }
        return height;
    }

    int findRightHeight(Node* root) {
        int height = 0;
        while(root) {
            height++;
            root = root->right;
        }
        return height;
    }

    int solve(Node* root) {
        if(!root) return 0;

        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);

        if(leftHeight == rightHeight) return (1 << leftHeight) - 1;
        return 1 + solve(root->left) + solve(root->right);
    }
    
    int countNodes(Node* root) {
        if(!root) return 0;
        
        return solve(root);
    }
};