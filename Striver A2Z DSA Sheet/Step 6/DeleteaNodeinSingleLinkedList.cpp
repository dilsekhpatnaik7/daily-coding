/*
Problem Link: https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

Node* deleteNode(Node *head, int x) {
    if(x == 1) {
        head = head->next;
        return head;
    }
    
    Node* node = head;
    int i = 1;
    while(i < x - 1) {
        node = node->next;
        i++;
    }
    node->next = node->next->next;
    return head;
}