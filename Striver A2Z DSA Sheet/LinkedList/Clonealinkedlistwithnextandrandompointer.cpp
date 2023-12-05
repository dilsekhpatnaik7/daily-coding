/*
Problem Link: https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    Node *copyList(Node *head) {
        if(!head) return head;

        unordered_map<Node*, Node*> map;
        Node* temp = head;
        while(temp) {
            map[temp] = new Node(temp->data);
            temp = temp->next;
        }
        temp = head;
        while(temp) {
            map[temp]->next = map[temp->next];
            map[temp]->arb = map[temp->arb];
            temp = temp->next;
        }
        return map[head];
    }

};