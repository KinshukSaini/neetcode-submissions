class MinStack {
public:
    stack<int> st;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> temp;
        int res = INT_MAX;
        while(!st.empty()){
            int n = st.top();
            temp.push(n);
            st.pop();
            res = min(res, n);
        }

        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }

        return res;
    }
};
