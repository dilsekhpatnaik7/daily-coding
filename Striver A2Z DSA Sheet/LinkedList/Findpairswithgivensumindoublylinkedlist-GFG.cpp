/*
Problem Link: https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    Node* findTail(Node* head) {
        Node* temp = head;
        while(temp->next) temp = temp->next;
        return temp;
    }

    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        if(!head) return {};

        vector<pair<int, int>> ans;
        Node* left = head;
        Node* right = findTail(head);
        while(left->data < right->data) {
            if(left->data + right->data == target) {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            } else if(left->data + right->data < target) {
                left = left->next;
            } else right = right->prev;
        }
        return ans;
    }
};