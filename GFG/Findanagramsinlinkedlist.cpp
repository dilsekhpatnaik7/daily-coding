// Problem Link: https://practice.geeksforgeeks.org/problems/de6f6a196aecdfb3e4939ba7729809a5a4bdfe90/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

/*
Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
       vector<int> v(26, 0);     
        for(int i = 0; i < s.size(); i++) {
            v[s[i] - 'a']++;
        }
        vector<Node*> res;
        int k = s.size();
        Node* curr = head, *start = head;
        vector<int> a(26, 0);
        vector<int> b(26, 0);
        while(curr != NULL){
            a[curr->data - 'a']++;
            k--;
            if(k==0) {
                if(v==a) {
                    res.push_back(start);
                    Node*temp = curr->next;
                    curr->next = NULL;
                    curr = temp;
                    start = temp;
                    a = b;
                    k = s.size();
                }
                else {
                    a[start->data - 'a']--;
                    k++;
                    start = start->next;
                    curr = curr->next;
                }
            }
            else {
                curr = curr->next;
            }
        }
        return res;      
    }
};