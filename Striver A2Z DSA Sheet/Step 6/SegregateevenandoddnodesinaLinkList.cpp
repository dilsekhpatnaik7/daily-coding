/*
Problem Link: https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
public:
    Node* divide(int N, Node *head) {
        if(!head) return head;
        
        Node* node = head;
        Node* evenList = NULL;
        Node* oddList = NULL;
        Node* even = NULL;
        Node* odd = NULL;
        
        while(node) {
            if(node->data % 2 == 0) {
                if(!evenList) {
                    evenList = node;
                    even = node;
                } else {
                    evenList->next = node;
                    evenList = evenList->next;
                }
            } else {
                if(!oddList) {
                    oddList = node;
                    odd = node;
                } else {
                    oddList->next = node;
                    oddList = oddList->next;
                }
            }
            node = node->next;
        }
        
        if(evenList) evenList->next = odd;
        if(oddList) oddList->next = NULL;
        
        if(even) return even;
        return odd;
    }
};