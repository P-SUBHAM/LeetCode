// Approach 3: count states
// ABA
// C C
// ABA
//  D
class Solution {
public:
    static const int mod = 1e9+7;
    int knightDialer(int n) {
        if(n == 1) return 10;
        int A = 4, B = 2, C = 2, D = 1;
        while(--n) {
            int _A = (1ll * 2 * (B + C)) % mod;
            int _B = A;
            int _C = (1ll * A + 2 * D) % mod;
            int _D = C;
            A = _A, B = _B, C = _C, D = _D;
        }
        return (1ll*A + B + C + D) % mod;
    }
};

// Dynamic Programming iterative
class Solution2 {
public:
    static const int mod = 1e9+7;
    bool isValid(int i, int j) {
        return 0 <= i && i < 4 && 0 <= j && j < 3 && !(i==3&&j==0) && !(i==3&&j==2);
    }
    vector<vector<int>> moves = {{+2,+1},{+2,-1},{-2,+1},{-2,-1},{+1,+2},{+1,-2},{-1,+2},{-1,-2}};
    static int dp[4][3][5001];
    static bool precompf;
    void precompute() {
        precompf = false;
        for(int i = 0; i < 12; i++) {
            int r = i/3;
            int c = i%3;
            if(isValid(r,c)) {
                dp[r][c][1] = 1;
            }
        }
        for(int t = 2; t <= 5000; t++) {
            for(int i = 0; i < 12; i++) {
                int r = i/3;
                int c = i%3;
                if(!isValid(r,c)) continue;
                for(auto move: moves) {
                    if(isValid(r+move[0],c+move[1])) {
                        dp[r][c][t] = (1ll*dp[r][c][t] + dp[r+move[0]][c+move[1]][t-1])%mod;
                    }
                }
            }
        }
    }
    int knightDialer(int n) {
        if(precompf) {
            precompute(); 
        }
        int ans = 0;
        for(int i = 0; i < 12; i++) {
            int r = i/3;
            int c = i%3;
            if(isValid(r,c)) {
                ans = (1ll*ans + dp[r][c][n])%mod;
            }
        }
        return ans;
    }
};
int Solution2::dp[4][3][5001];
bool Solution2::precompf = true;

// Approach 1: Dynamic Programming
class Solution1 {
public:
    static const int mod = 1e9+7;
    bool isValid(int i, int j) {
        return 0 <= i && i < 4 && 0 <= j && j < 3 && !(i==3&&j==0) && !(i==3&&j==2);
    }
    vector<vector<int>> moves = {{+2,+1},{+2,-1},{-2,+1},{-2,-1},{+1,+2},{+1,-2},{-1,+2},{-1,-2}};
    int dp[4][3][5001];
    int dpf(int r, int c, int n) {
        if(!isValid(r,c)) return 0;
        if(n == 1) return 1;
        if(dp[r][c][n] != -1) {
            // cout<<r<<" "<<c<<" "<<n<<":"<<dp[r][c][n]<<endl;
            return dp[r][c][n];
        }
        int ans = 0;
        for(auto move: moves) {
            ans = (1ll*ans + dpf(r+move[0],c+move[1],n-1))%mod;
        }
        // cout<<r<<" "<<c<<" "<<n<<":"<<ans<<endl;
        return dp[r][c][n] = ans;
    }
    int knightDialer(int n) {
        int ans = 0;
        memset(dp,-1,sizeof(dp)); // memset works for 0 or -1 only as byte based
        for(int i = 0; i < 12; i++) {
            int r = i/3;
            int c = i%3;
            if(isValid(r,c)) {
                ans = (1ll*ans + dpf(r,c,n))%mod;
            }
        }
        return ans;
    }
};