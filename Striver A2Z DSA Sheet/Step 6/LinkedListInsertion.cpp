/*
Problem Link: https://practice.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
        Node* node = new Node(x);
        if(!head) return node;
        
        node->next = head;
    }
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
        Node* node = new Node(x);
        if(!head) return node;
        
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = node;
        return head;
    }
};