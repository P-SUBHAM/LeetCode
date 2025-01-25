// Approach 1: Digit DP
class Solution {
public:
    int dp[12][2][12];
    // idx is index of string no, tight is tighbound, cnt is no of 1s in string till idx
    int digit1(string &n, int idx, int tight, int cnt) {
        if(idx == n.size()) return cnt;
        if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];
        int limit = (tight==true?n[idx]-'0':9);
        int ans = 0;
        for(int i = 0; i <= limit; i++) {
            int ncnt = cnt + (i==1?1:0);
            ans += digit1(n,idx+1,tight&(i==n[idx]-'0'),ncnt);
        }
        return dp[idx][tight][cnt] = ans;
    }
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string N = to_string(n);
        return digit1(N,0,1,0);
    }
};