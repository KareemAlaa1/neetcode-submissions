class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        bool check = true;
        int op1, op2;
        for(auto op:tokens){
            if(op.size() == 1 && (op[0] == '+' || op[0] == '-' || op[0] == '*' || op[0] == '/')){
                op2 = st.top();
                st.pop();                
                op1 = st.top();
                st.pop();
                if(op[0] == '+'){
                    op1+=op2;
                }else if(op[0] == '-'){
                    op1-=op2;
                }else if(op[0] == '*'){
                    op1*=op2;
                }else{
                    op1/=op2;
                }
                st.push(op1);
            }else{
                st.push(stoi(op));
            }
        }
        return st.top();   
    }
};
