/*
Problem Link: https://practice.geeksforgeeks.org/problems/find-length-of-loop/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

int solve(Node* slow, Node* node) {
    int count = 1;
    while(slow != node) {
        node = node->next;
        count++;
    }
    return count;
}

int countNodesinLoop(struct Node *head) {
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return solve(slow, slow->next);
        }
    }
    return 0;
}