class MinStack {
public:
    stack<int> left;
    stack<int> right;
    stack<int> st;
    MinStack() {
    }
    
    void push(int val) {
        if(left.empty() || left.top() > val){
            left.push(val);
            st.push(0);
        }
        else{
            right.push(val);
            st.push(1);
        }
    }
    
    void pop() {
        if(st.top() == 0) left.pop();
        else right.pop();
        st.pop();
    }
    
    int top() {
        if(st.top() == 0) return left.top();
        return right.top();
    }
    
    int getMin() {
        return left.top();
    }
};
