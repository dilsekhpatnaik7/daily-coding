/*
Problem Link: https://www.codingninjas.com/studio/problems/check-if-linked-list-is-palindrome_985248?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(1)
*/

/****************************************************************

    Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node()
        {
            this->data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
    };

*****************************************************************/
Node* getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* reverseList(Node* head) {
    if(!head) return nullptr;

    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = current->next;

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

bool isPalindrome(Node *head) {
    Node* mid = getMiddle(head);
    Node* secondHead = reverseList(mid);

    while(head && secondHead) {
        if(head->data != secondHead->data) return false;
        head = head->next;
        secondHead = secondHead->next;
    }
    return true;
}