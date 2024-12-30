// Approach 1: Dynamic Programming Tabulation
// dp[i][j] = (str[i]==str[j]) && dp[i+1][j-1]
class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool> (n, 0));
        // filing 1 len substr
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        // filling 2 len substr dp[i][i+1]
        for(int j = 1; j < n; j++) {
            int i = j - 1;
            if(s[i] == s[j]) {
                dp[i][j] = 1;
            }
        }
        // iterate for rest half i < j dp[i][i+2..n] diagonally
        for(int J = 2; J < n; J++) {
            for(int i = 0, j = J; i < n - 1 && j < n; i++, j++) {
                dp[i][j] = (s[i] == s[j])&&(dp[i+1][j-1]);
            }
        }
        // iterate and check max substring from dp table
        int maxv = 0; pair<int,int> coor;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(dp[i][j]) {
                    if(j - i + 1 > maxv) {
                        maxv = j - i + 1;
                        coor = {i,j};
                    }
                }
            }
        }
        // print dp matrix for reference
        // for(auto x: dp) {for(auto y: x) {cout<<y<<" ";}cout<<endl;}

        return s.substr(coor.first,maxv);
    }
};