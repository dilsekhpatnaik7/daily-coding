/*
Problem Link: https://practice.geeksforgeeks.org/problems/sort-a-stack/1

Time Complexity: O(N ^ 2)
Space Cmplexity: O(N)
*/

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insertCorrectPosition(int x, stack<int>& s) {
    if(s.size() == 0 or s.top() < x) {
        s.push(x);
    } else {
        int a = s.top();
        s.pop();
        insertCorrectPosition(x, s);
        s.push(a);
    }
}

void reverse(stack<int>& s) {
    if(s.size() > 0) {
        int x = s.top();
        s.pop();
        reverse(s);
        insertCorrectPosition(x, s);
    }
}

void SortedStack :: sort() {
    reverse(s);
}