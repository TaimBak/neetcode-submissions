class MinStack {
private:
    stack<int> s;
    stack<int> minS;

public:
    MinStack() {

    }
    
    void push(int val)
    {
        s.push(val);
        val = min(val, minS.empty() ? val : minS.top());
        minS.push(val);
    }
    
    void pop() {
        s.pop();
        minS.pop();
    }
    
    int top() {
        return s.top();
        
    }
    
    int getMin() {
        return minS.top();
    }
};
