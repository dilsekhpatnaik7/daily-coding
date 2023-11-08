/*
Problem Link: https://practice.geeksforgeeks.org/problems/binary-tree-representation/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
public:
    node* solve(int index, vector<int> &vec) {
        if(index >= vec.size()) return NULL;
        
        struct node *root = newNode(vec[index]);
        root->left = solve(index*2 + 1, vec);
        root->right = solve(index*2 + 2, vec);
        
        return root;
    }
    
    void create_tree(node* &root0, vector<int> &vec){
        root0 = solve(0, vec);
    }
};