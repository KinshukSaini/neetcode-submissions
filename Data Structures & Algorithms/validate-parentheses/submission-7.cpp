class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        map<char, char> mpp = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else{
                if(!st.empty() && mpp[c] == st.top()) st.pop();
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
