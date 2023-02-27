// Problem Link: https://practice.geeksforgeeks.org/problems/bae68b4d6a2a77fb6bd459cf7447240919ebfbf5/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    Node *reverse(Node *head, int k) {
        Node* tmp = NULL, *ptr = head, *res = head;
        for(int i = 0; i<k || ptr; i++) {
            if(i==k) {
                res = tmp;
                tmp = NULL;
            }
            Node* next = ptr->next;
            ptr->next = tmp;
            tmp = ptr;
            ptr = next;
        }
        head->next = tmp;
        return res;
    }
};