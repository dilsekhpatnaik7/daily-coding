// Problem Link: https://practice.geeksforgeeks.org/problems/da62a798bca208c7a678c133569c3dc7f5b73500/0
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    Node *merge(Node *a, Node *b) {
        Node *temp = new Node(0);
        Node *res = temp;

        while (a != NULL && b != NULL) {
            if (a->data < b->data) {
                temp->bottom = a;
                temp = temp->bottom;
                a = a->bottom;
            }
            else {
                temp->bottom = b;
                temp = temp->bottom;
                b = b->bottom;
            }
            if (a != NULL)
                temp->bottom = a;
            else
                temp->bottom = b;
        }
        return res->bottom;
    }

    Node *flatten(Node *root) {
        if (root == NULL || root->next == NULL)
            return root;

        root->next = flatten(root->next);

        root = merge(root, root->next);
        
        return root;
    }
};