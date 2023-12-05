/*
Problem Link: https://practice.geeksforgeeks.org/problems/reverse-a-stack/1

Time Complexity: O(N ^ 2)
Space Cmplexity: O(N)
*/

class Solution{
public:
    void insertAtPosition(int x, stack<int>& St) {
        if(St.size() == 0) St.push(x);
        else {
            int a = St.top();
            St.pop();
            insertAtPosition(x, St);
            St.push(a);
        }
    }

    void reverse(stack<int>& St) {
        if(St.size() > 0) {
            int x = St.top();
            St.pop();
            reverse(St);
            insertAtPosition(x, St);
        }
    }
    void Reverse(stack<int> &St){
        reverse(St);
    }
};