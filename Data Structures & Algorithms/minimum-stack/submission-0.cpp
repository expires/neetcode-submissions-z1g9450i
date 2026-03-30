class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty())
        {
            min = val;
        }

        s.push({val, min});

        if (val < min)
        {
            min = val;
        }
    }
    
    void pop() {

        if (s.top().first == min)
        {
            min = s.top().second;
        }

        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return min;
    }
private:
    int min;
    stack<pair<int, int>> s;
};
