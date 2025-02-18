// Approach 2: O(n)
// keep assigning number 1 to n+1 if I ok
// if D D seq then reverse that part (stack)
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans = ""; stack<char> st;
        for(int i = 1; i <= n+1; i++) {
            char ch = '0'+i;
            st.push(ch);
            // cout<<i<<pattern[i-1]<<endl;
            if(i==n+1 || pattern[i-1]=='I') { // whenever I whatever is contrib by D rev it, or else if its end and if it was D then also we need to invert
                
                while(!st.empty()) {
                    ans += st.top(); st.pop();
                }
            }
        }
        return ans;
    }
};

// Approach 1: BackTracking
// create set of chars, for a given pos choose the smallest char from set, then check if we can form a valid sequence from that, if not backtrack, else we have lexicographically smallest sequence
class Solution1 {
public:
    string ans, pat;
    bool DI(string s, set<char> &st,int i) {
        // cout<<s<<endl; // backTracking str pattern print
        if(i == pat.size()+1) { //cout<<"ans:"<<s<<endl;
            ans = s; return true;
        }
        set<char> tempst = st; 
        for(auto ch: tempst) {
            char prev = s[i-1], curr = ch;
            if(pat[i-1] == 'I') { // i-1 < i
                if(prev > curr) continue; // not valid
            }
            else { // i-1 > i
                if(prev < curr) continue; // not valid
            }
            st.erase(ch);
            if(DI(s+string(1,ch),st,i+1)) return true;
            st.insert(ch); // back tracking
        }
        return false;
    }
    string smallestNumber(string pattern) {
        int n = pattern.size();
        ans = ""; pat = pattern; set<char> st;
        for(char i = '1'; i <= '9'; i++) st.insert(i);
        // for(auto ch: st) cout<<ch<<" "; cout<<endl;
        for(char i = '1'; i <= '9'; i++) {
            st.erase(i);
            if(DI(""+string(1,i),st,1)) return ans;
            st.insert(i);
        }
        return ans;
    }
};