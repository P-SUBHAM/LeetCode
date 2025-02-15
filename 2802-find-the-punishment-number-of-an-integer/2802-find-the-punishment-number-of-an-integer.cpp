// Approach 1: Dp to find if a number is punishable or not
class Solution {
public:
    struct pair_hash{
        int operator()(pair<int,int> p) const { // unordered_map expects a const hash function
            int h1 = hash<int>{}(p.first);
            int h2 = hash<int>{}(p.second);
            return h1^(h2<<1);
        }
    };
    unordered_map<pair<int,int>,bool,pair_hash> dp;
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
// T: 387ms Beats 16.37%; S: 130.01MB Beats 12.34%

// Approach 1: Dp to find if a number is punishable or not
class Solution1 {
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
// T: 626ms Beats 14.86%; S: 118.62MB Beats 13.10%