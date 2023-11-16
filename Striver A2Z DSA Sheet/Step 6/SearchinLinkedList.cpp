/*
Problem Link: https://practice.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
  public:
    bool searchKey(int n, struct Node* head, int key) {
        struct Node* node = head;
        while(node) {
            if(node->data == key) return true;
            node = node->next;
        }
        return false;
    }
};