class Solution {
public:
    int calculate(string s) {
        s += "+";
        int term = 0;
        int total = 0;
        char op = '+'; // prev operand
        char ch;
        stack<int> st; st.push(0);
        for(int i = 0; i < s.size(); i++) {
            ch = s[i];
            if(ch == ' ') continue;
            if(isdigit(ch)) {
                term *= 10;
                term += ch - '0';
            }
            else {
                if(op == '+' || op == '-') {
                    int op2 = term * ((op == '+')?1:-1); // brackets imp
                    st.push(op2);
                }
                else {
                    int op1 = st.top(); st.pop();
                    int op2 = term;
                    int val = ((op == '*')?(op1*op2):(op1/op2));
                    st.push(val);
                }
                op = ch;
                term = 0;
            }

            // // debugStart
            // stack<int> st2;
            // while(!st.empty()) { st2.push(st.top()); st.pop();}
            // cout<<"Stack:"; 
            // while(!st2.empty()) {st.push(st2.top()); cout<<st2.top()<<" "; st2.pop();}
            // cout<<" term:"<<term<<" op:"<<op<<" ch:"<<ch<<endl;
            // // DebugEnd
        }
        while(!st.empty()) {
            int stElements = st.top(); st.pop();
            total += stElements;
        }
        return total;
    }
};