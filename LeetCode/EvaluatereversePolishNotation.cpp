// Problem Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<long>stk;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]!="+" && tokens[i]!="/" && tokens[i]!="*" && tokens[i]!="-")
            {
                long t=stoi(tokens[i]);
                stk.push(t);
            }
            else
            {
                long a=stk.top();
                stk.pop();
                long b=stk.top();
                stk.pop();
                string ch=tokens[i];
                long c=0;
                if(ch=="+")
                c=b+a;
                if(ch=="-")
                c=b-a;
                if(ch=="*")
                c=b*a;
                if(ch=="/")
                c=b/a;
                stk.push(c);
            }
        }
        return int(stk.top());    
    }
};