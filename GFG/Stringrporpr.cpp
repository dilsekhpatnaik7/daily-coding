// Problem Link: https://practice.geeksforgeeks.org/problems/d25f415de2ff3e02134de03e17ad019d723ab2e9/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{   
public:
    long long remove2(string &s, string b, stack<char> &temp1) {
        long long int count2 = 0;
        stack <char>temp2;
        temp2.push(temp1.top());
        temp1.pop();
        while(!temp1.empty()) {
            if(!temp2.empty() && (temp1.top() == b[0] && temp2.top() == b[1])) {
                temp1.pop();
                temp2.pop();
                count2++;
            }
            else{
                temp2.push(temp1.top());
                temp1.pop();
            }
        }
        return count2;
    }
    
    long long remove1(string &s,string a, string b,int X,int Y) {
        int n = s.size();
        long long int count1 = 0, count2 = 0;
        stack<char>temp1;
        temp1.push(s[0]);
        
        for(int i = 1; i < n; i++) {
            if(!temp1.empty() && (temp1.top() == a[0] && s[i] == a[1])) {
                temp1.pop();
                count1++;
            }
            else temp1.push(s[i]);
        }
        count2 = remove2(s, b, temp1);
        return count1 * X + count2 * Y;
    }

    long long solve(int X, int Y, string S) {
        string string1 = "pr";
        string string2 = "rp";
      
      
        if(X>Y) return remove1(S, string1, string2, X, Y);
        else {
            swap(X, Y);
            return remove1(S, string2, string1, X, Y);
        }
    }
};