/*
Problem Link: https://practice.geeksforgeeks.org/problems/rearrange-a-linked-list/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    void rearrangeEvenOdd(Node *head) {
        if(!head) return;

        Node* odd = head;
        Node* even = head->next;
        Node* evenStart = even;
    
        while(even && even->next) {
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenStart;
    }
};