class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1) return stoi(tokens[0]); 
        stack<string> st;
        int res = 0;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();

                if(tokens[i] == "+") res = a + b;
                if(tokens[i] == "-") res = b - a;
                if(tokens[i] == "*") res = a * b;
                if(tokens[i] == "/") res = b / a;

                st.push(to_string(res));
            }
            else st.push(tokens[i]);
        }
        return res;
    }
};
