/*
Problem Link: https://leetcode.com/problems/rotate-list/description/

Time Complexity: O(N)
Space Complexity: O(N)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getTail(ListNode* head) {
        while(head->next) {
            head = head->next;
        }
        return head;
    }

    int getLength(ListNode* head) {
        int length = 0;
        while(head) {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode* findNNode(ListNode* head, int n) {
        int count = 1;
        while(head) {
            if(count == n) return head;
            count++;
            head = head->next;
        }
        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;

        int length = getLength(head);
        ListNode* tail = getTail(head);
        if(k % length == 0) return head;
        k = k % length;

        tail->next = head;
        ListNode* newLastNode = findNNode(head, length - k);
        head = newLastNode->next;
        newLastNode->next = nullptr;

        return head;
    }
};