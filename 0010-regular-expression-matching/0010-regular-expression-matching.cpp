class Solution {
public:
    vector<vector<int>> dp;
    bool match(char ch1, char ch2) {
        if(ch2 == '.') return true;
        return ch1 == ch2;
    }
    bool dpf(string &s, string &p, int i, int j, int n1, int n2) {
        if(dp[i][j] != -1) return dp[i][j];
        if(i == n1 && j == n2) return dp[i][j] = true;
        if(i == n1 && j != n2) return dp[i][j] = (p[j+1] == '*') && dpf(s,p,i,j+2,n1,n2);
        if(j == n2) return dp[i][j] = false;
        // p: xy x* x
        if(j+1 < n2 && p[j+1] == '*') { // x* i.e .* a* b*
            bool incl = match(s[i],p[j]) && dpf(s,p,i+1,j,n1,n2);
            bool excl = dpf(s,p,i,j+2,n1,n2);
            return dp[i][j] = incl || excl;
        }
        else { // no star -> xy or x
            return dp[i][j] = match(s[i],p[j]) && dpf(s,p,i+1,j+1,n1,n2);
        }
        return true;
    }
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        dp.clear();
        dp.resize(n1+1,vector<int> (n2+1,-1));
        return dpf(s,p,0,0,n1,n2);
    }
};

class Solution1 {
public:
    bool isMatch(string S, string P) {
        if(!P.size()) {
            cout<<S<<":"<<P<<endl;
            return (!S.size());
        }
        bool match = bool(S.size()) && (P[0] == S[0] or P[0] == '.');
        if(P.size() >= 2 and P[1] == '*') {
            return isMatch(S,P.substr(2,P.size()-1)) || (match && isMatch(S.substr(1,S.size()-1),P));
        }
        else {
            return match && isMatch(S.substr(1,S.size()-1),P.substr(1,P.size()-1));
        }
    }
};