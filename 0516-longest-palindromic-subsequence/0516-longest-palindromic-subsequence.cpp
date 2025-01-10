// Approach 1: LCS(s,rev(s))
/* 
LCS Approach:
start from both end, f(i,j) = longest common subsequence between w1[:i] &w2[:j]
[:i][:j] = (i==j) + [:i-1][:j-1] or max([:i][:j-1],[:i-1]][:j])
if i,j th char match count for i-1,j-1 else exclude once i or j 
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev = s; reverse(rev.begin(),rev.end());
        return longestCommonSubsequence(s,rev);
    }

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