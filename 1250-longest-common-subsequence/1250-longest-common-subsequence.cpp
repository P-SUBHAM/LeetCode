// Approach 1: Memoization 2D array
/* start from both end, f(i,j) = longest common subsequence between w1[:i] &w2[:j]
[:i][:j] = (i==j) + [:i-1][:j-1] or max([:i][:j-1],[:i-1]][:j])
if i,j th char match count for i-1,j-1 else exclude once i or j 
*/

// Approach 2: Find the lcs string
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<string>> dp(n1, vector<string>(n2, "-1"));
        function<string(int, int)> dpf = [&](int i, int j) -> string {
            if(i == -1 or j == -1) {return "";}
            if(dp[i][j] != "-1") {return dp[i][j];}
            if(text1[i] == text2[j]) {return dp[i][j]=(dpf(i-1,j-1) + text1[i]);}
            string s1 = dpf(i-1,j), s2 = dpf(i,j-1);
            if(s1.size() > s2.size()) {return dp[i][j]=s1;}
            else {return dp[i][j]=s2;}
        };
        string ans = dpf(n1 - 1, n2 - 1);
        // cout<<ans;
        return ans.size();
    }
};

// Approach 1.1 : lcs with lambda function
class Solution1_1 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        function<int(int, int)> dpf = [&](int i, int j) -> int {
            if (i == -1 || j == -1) {
                return 0;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            if (text1[i] == text2[j]) {
                return dp[i][j] = 1 + dpf(i - 1, j - 1);
            }
            return dp[i][j] = max(dpf(i - 1, j), dpf(i, j - 1));
        };
        return dpf(n1 - 1, n2 - 1);
    }
};

class Solution1 {
public:
    vector<vector<int>> dp;
    int dpf(string &text1, string &text2, int i, int j) {
        if(i == -1 or j == -1) {
            return 0;
        }
        if(dp[i][j] != -1) {return dp[i][j];}
        if(text1[i] == text2[j]) {
            return dp[i][j] = 1 + dpf(text1,text2,i-1,j-1);
        }
        return dp[i][j] = max(dpf(text1,text2,i-1,j),dpf(text1,text2,i,j-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        dp.clear();
        dp.resize(n1,vector<int>(n2,-1));
        return dpf(text1,text2,n1-1,n2-1);
    }
};