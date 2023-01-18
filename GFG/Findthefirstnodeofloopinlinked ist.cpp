// Problem Link: https://practice.geeksforgeeks.org/problems/44bb5287b98797782162ffe3d2201621f6343a4b/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    int findFirstNode(Node* head) {
        Node* fast = head;
        Node* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                break;
            }
        }
        if(fast == NULL || fast->next == NULL){
            return -1;
        }
        Node* temp = head;
        while(temp != slow){
            temp = temp->next;
            slow = slow->next;
        }
        return temp->data;
    }
};