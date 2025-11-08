class MyStack {
    queue<int> _frontier;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        _frontier.push(x);
    }
    
    int pop() {
        queue<int> tmp;
        while (_frontier.size() > 1) {
            tmp.push(_frontier.front());
            _frontier.pop();
        }
        int val = _frontier.front(); _frontier.pop();        

        while (!tmp.empty()) {
            _frontier.push(tmp.front()); tmp.pop();
        }

        return val;
    }
    
    int top() {
        queue<int> tmp;
        while (_frontier.size() > 1) {
            tmp.push(_frontier.front());
            _frontier.pop();
        }
        int val = _frontier.front(); _frontier.pop();
        tmp.push(val);
        while (!tmp.empty()) {
            _frontier.push(tmp.front());
            tmp.pop();
        }
        return val;
    }
    
    bool empty() {
        return _frontier.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */