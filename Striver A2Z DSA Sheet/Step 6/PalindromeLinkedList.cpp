/*
Problem Link: https://leetcode.com/problems/palindrome-linked-list/description/

Time Complexity: O(N)
Space Complexity: O(1)
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
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nextNode = current->next;

        while(current) {
            current->next = prev;
            prev = current;
            current = nextNode;
            if(nextNode) {
                nextNode = nextNode->next;
            }
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* mid = getMiddle(head);
        ListNode* secondHead = reverseList(mid);

        while(head && secondHead) {
            if(head->val != secondHead->val) return false;
            head = head->next;
            secondHead = secondHead->next;
        }
        return true;
    }
};