class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mpp;
        mpp['('] = ')';
        mpp['{'] = '}';
        mpp['['] = ']';
        
        for(char c : s){
            if(st.empty()){
                st.push(c);
            }
            else{
                if(mpp[st.top()] == c){
                    st.pop();
                }
                else st.push(c);
            }
        }
        return st.empty();
    }
};
