/*
Problem Link: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    Node* segregate(Node *head) {
        int count[3] = {0};
        Node* node = head;
        while(node) {
            count[node->data]++;
    
            node = node->next;
        }
        
        node = head;
        int index = 0;
        while(node) {
            if(count[index] == 0) index++;
            if(count[index] != 0) {
                node->data = index;
                count[index]--;
                node = node->next;
            }
        }
        return head;
    }
};