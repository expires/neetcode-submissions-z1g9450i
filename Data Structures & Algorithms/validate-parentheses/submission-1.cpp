class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> items = 
        {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };

        for (char c : s)
        {
            if (items.count(c))
            {
                if (!st.empty() && st.top() == items[c]) {
                    st.pop();
                } else {
                    return false;
                }
            }
            else
            {
                st.push(c);
            }
        }


        return st.empty();
        

    }
};
