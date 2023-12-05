/*
Problem Link: https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
    public:
    struct node* reverseList(struct node* head) {
        if(!head) return nullptr;
    
        struct node* prev = nullptr;
        struct node* current = head;
        struct node* nextNode = current->next;
    
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
    
    struct node* getKNode(struct node* temp, int k) {
        k -= 1;
        while(temp->next && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    
    struct node *reverse (struct node *head, int k) { 
        struct node* temp = head;
        struct node* prevLast = nullptr;
        while(temp) {
            struct node* kNode = getKNode(temp, k);
            if(!kNode) {
                if(prevLast) prevLast->next = temp;
                break;
            } 
    
            struct node* nextNode = kNode->next;
            kNode->next = nullptr;
            struct node* reversed = reverseList(temp);
            if(temp == head) {
                head = kNode;
            } else {
                prevLast->next = kNode;
            }
    
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};