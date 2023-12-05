// Problem Link: https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=pairwise-swap-elements-of-a-linked-list-by-swapping-data

/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution {
public:
    Node* pairWiseSwap(struct Node* head) {
        if(head==NULL || head->next==NULL) return head;
        Node *first=head,*second=head->next;
        
        Node *nxt = second->next;
        second->next = first;
        first->next = pairWiseSwap(nxt);
        
        return second;
    }
};