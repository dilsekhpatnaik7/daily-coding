/*
Problem Link: https://practice.geeksforgeeks.org/problems/count-nodes-of-linked-list/1

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
    public:
    int getCount(struct Node* head) {
        int count = 0;
        struct Node* node = head;
        while(node) {
            count++;
            node = node->next;
        }
        return count;
    }
};