class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char c : s){
            if(c == ')'){
                if(st.empty()) return false;
                if(st.top() != '('){
                    return false;
                }
                st.pop();
            }
            else if(c == '}'){
                if(st.empty()) return false;
                if(st.top() != '{'){
                    return false;
                }
                st.pop();
            }
            else if(c == ']'){
                if(st.empty()) return false;
                if(st.top() != '['){
                    return false;
                }
                st.pop();
            }
            else st.push(c);
        }
        return (st.empty());
    }
};
