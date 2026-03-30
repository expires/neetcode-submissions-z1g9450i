class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (string ss: tokens)
        {
            
            if (ss == "*")
            {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(a*b);
            } 
            else if (ss == "-")
            {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b - a);
            } 
            else if (ss == "+")
            {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(a+b);
            } 
            else if (ss == "/")
            {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b / a);
            } 
            else
            {
                s.push(stoi(ss));
            }
        }
        
        return s.top();
    }
};
