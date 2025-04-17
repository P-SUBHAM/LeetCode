static const int MOD = 1000000007;
class Solution {
public:
    int countNumbers(string l, string r, int b) {
        string lm1 = decSubtractOne(l);
        int cntR = countUp(r, b);
        int cntL = countUp(lm1, b);
        int ans = cntR - cntL;
        if (ans < 0) ans += MOD;
        return ans;
    }
    string decSubtractOne(string s) {
        if (s == "0") return "-1";
        int i = s.size() - 1;
        while (i >= 0 && s[i] == '0') {
            s[i] = '9';
            --i;
        }
        s[i]--;
        int p = 0;
        while (p + 1 < s.size() && s[p] == '0') p++;
        return s.substr(p);
    }
    vector<int> toBase(const string &s, int b) {
        vector<int> digits;
        string cur = s;
        while (cur != "0") {
            int carry = 0;
            string nxt;
            for (char c : cur) {
                int x = carry * 10 + (c - '0');
                int q = x / b;
                carry = x % b;
                if (!nxt.empty() || q != 0) 
                    nxt.push_back(char('0' + q));
            }
            digits.push_back(carry);
            cur = nxt.empty() ? "0" : nxt;
        }
        if (digits.empty()) 
            digits.push_back(0);
        reverse(digits.begin(), digits.end());
        return digits;
    }
    int countUp(const string &X, int b) {
        if (X.size() && X[0] == '-') 
            return 0;           
        auto D = toBase(X, b);
        int n = D.size();
        vector<vector<int>> dp(b, vector<int>(2, 0)), ndp(b, vector<int>(2, 0));
        dp[0][1] = 1; 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < b; ++j)
                ndp[j][0] = ndp[j][1] = 0;
            for (int last = 0; last < b; ++last) {
                for (int tight = 0; tight < 2; ++tight) {
                    int ways = dp[last][tight];
                    if (!ways) continue;
                    int mx = tight ? D[i] : (b - 1);
                    for (int d = last; d <= mx; ++d) {
                        int nt = tight && (d == mx);
                        ndp[d][nt] = (ndp[d][nt] + ways) % MOD;
                    }
                }
            }
            dp.swap(ndp);
        }
        int res = 0;
        for (int last = 0; last < b; ++last)
            for (int t = 0; t < 2; ++t)
                res = (res + dp[last][t]) % MOD;
        return res;
    }
};