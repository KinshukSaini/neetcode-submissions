class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        if(tokens.size() == 0) return 0;
        for(string token : tokens){
            if( token == "+" ||
                token == "-" ||
                token == "*" ||
                token == "/" ){
                
                int second = operands.top();
                operands.pop();
                int first = operands.top();
                operands.pop();
                int num;
                if(token == "+") num = first + second;
                else if(token == "-") num = first - second;
                else if(token == "*") num = first * second;
                else num = first / second;

                operands.push(num);
            }
            else{
                operands.push(stoi(token));
            }
        }

        return operands.top();
    }
};
