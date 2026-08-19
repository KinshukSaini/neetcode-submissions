class MinStack {
public:
    stack<int> left;
    stack<int> right;
    stack<int> log;
    MinStack() {
        
    }
    
    void push(int val) {
        if(left.empty()){
            left.push(val);
            log.push(0);
        }
        else{
            if(val < left.top()){
                left.push(val);
                log.push(0);
            }
            else{
                right.push(val);
                log.push(1);
            }
        }
    }
    
    void pop() {
        if(log.top() == 1) right.pop();
        else left.pop();
        log.pop();
    }
    
    int top() {
        if(log.top()) return right.top();
        else return left.top();
    }
    
    int getMin() {
        return left.top();
    }
};
