/*
Problem Link: https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
        Node* getTail(Node* head) {
         while(head->next) {
              head = head->next;
         }
         return head;
    }
    
    int getLength(Node* head) {
         int length = 0;
         while(head) {
              length++;
              head = head->next;
         }
         return length;
    }
    
    Node* findNNode(Node* head, int n) {
         int count = 1;
         while(head) {
              if(count == n) return head;
              count++;
              head = head->next;
         }
         return head;
    }
    
    Node* rotate(Node* head, int k) {
        if(!head || k == 0) return head;

        int length = getLength(head);
        Node* tail = getTail(head);
        k = k % length;
        if(k % length == 0) return head;
        
        tail->next = head;
        Node* newLastNode = findNNode(head, k);
        head = newLastNode->next;
        newLastNode->next = nullptr;
        
        return head;
    }
};