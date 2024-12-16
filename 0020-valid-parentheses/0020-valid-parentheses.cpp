class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        // mapping right brackets to left brackets for easy access
        unordered_map<char,char> mp = {{')','('},{']','['},{'}','{'}};
        for(int i = 0; i < n; i++) {
            char x = s[i];
            // if empty add
            if(st.empty()) {
                st.push(x);
            }
            // if left ({[ insert, else for right check for left compliment if not matched return false
            else {
                if(x == '(' or x == '[' or x == '{') {
                    st.push(x);
                }
                // right brackets
                else {
                    if(st.empty()) {
                        return false;
                    }
                    if(mp[x] == st.top()) {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        if(st.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};