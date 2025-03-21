// Approach 1: Stack
class Solution {
public:
    int calculate(string s) {
        s = string(1,'(') + s + string(1,')');
        int cur = 0, res = 0, sign = 1, n = s.size(), ans = 0;
        stack<int> st;
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(ch == ' ') continue;
            if(isdigit(ch)) { // create current no from str
                cur = cur*10+stoi(string(1,ch)); continue;
            }
            if(ch == '+' || ch == '-') { // if new + - eg +0+3'+' // u do prev val u cal using sign*curr(prev to sign) add it to res(running sum) 
                res += cur*sign;
                cur = 0;
                sign = ch=='+'?1:-1; continue;
            }
            if(ch == '(') { // whatever is prev running sum(res)+sign*'(' // store prev res and curr sign for brac
                st.push(res);
                st.push(sign);
                cur = 0; sign = 1; res=0; continue;
            }
            if(ch == ')') {
                res += sign*cur; // this res has current running sum
                sign = st.top(); st.pop(); // sign for ( which got closed)
                int lastres = st.top(); st.pop();// prev to it x+()
                res = lastres + res*sign; //res = x+sign*(res) // res+=si*curr; then res*=sign; then res+=st.top(lastres)
                cur = 0; sign = 1; continue;
            }
        }
        // res += cur;
        while(!st.empty()) {
            res*=st.top();st.pop();
            res+=st.top(); st.pop();
        }
        return res;
    }
};