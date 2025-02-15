// Approach 1: Dp to find if a number is punishable or not
class Solution {
public:
    map<pair<int,int>,bool> dp;
    bool punishable(int digitstr, int n) {
        if(dp.find({digitstr,n})!=dp.end()) return dp[{digitstr,n}];
        if(digitstr < n || n < 0) return dp[{digitstr,n}] = false;
        if(digitstr == n) return dp[{digitstr,n}] = true;
        for(int i = 10; i <= 10*digitstr ; i *= 10) {
            int num = digitstr%i;
            int newdigitstr = digitstr/i;
            if(punishable(newdigitstr,n-num)) {
                return dp[{digitstr,n}] = true;
            }
        }
        return dp[{digitstr,n}] = false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(punishable(i*i,i)) ans += i*i;
        }
        return ans;
    }
};