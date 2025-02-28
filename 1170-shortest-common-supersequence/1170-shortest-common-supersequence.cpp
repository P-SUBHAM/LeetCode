// Practice
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = longestCommonSubsequence(str1,str2), ans = "";
        int i = 0, j = 0, k = 0, n1 = str1.size(), n2 = str2.size(), n3 = lcs.size();
        while(i < n1 or j < n2) {
            if(k != n3) {
                if(str1[i] != lcs[k]) {
                    ans += str1[i]; i++; continue;
                }
                if(str2[j] != lcs[k]) {
                    ans += str2[j]; j++; continue;
                }
                ans += lcs[k];
                k++; i++; j++;
            }
            else {
                if(i < n1) {
                    ans += str1[i]; i++;
                }
                if(j < n2) {
                    ans += str2[j]; j++;
                }
            }
        }
        return ans;
    }
    // main logic part
    string longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        string ans = "";
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if(text1[i-1]==text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        for(int i = n1, j = n2; i > 0 && j > 0; ) {
            if(text1[i-1]==text2[j-1]) {
                ans = text1[i-1] + ans; i--;j--;
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    i--;
                }
                else {
                    j--;
                }
            }
        }
        return ans;
    }
};
/////////////////////////

// Approach 1: using string lcs
// find lcs, str1,str2,lcs keep adding char from str1,2 as long as not matching lcs, once matched add once, then repeat till u have added all the chars from both str1,2
// Approach correct but memeory limit exceeded
class Solution1 {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = longestCommonSubsequence(str1,str2), ans = "";
        int i = 0, j = 0, k = 0, n1 = str1.size(), n2 = str2.size(), n3 = lcs.size();
        while(i < n1 or j < n2) {
            if(k != n3) {
                if(str1[i] != lcs[k]) {
                    ans += str1[i]; i++; continue;
                }
                if(str2[j] != lcs[k]) {
                    ans += str2[j]; j++; continue;
                }
                ans += lcs[k];
                k++; i++; j++;
            }
            else {
                if(i < n1) {
                    ans += str1[i]; i++;
                }
                if(j < n2) {
                    ans += str2[j]; j++;
                }
            }
        }
        return ans;
    }
    // print longest common subsequence using DP tabular method and regenarating string
    string longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0)); // 0 index->boundary
        for(int i = 1; i <= n1; i++) { // DP table tabulation
            for(int j = 1; j <= n2; j++) {
                if(text1[i-1] == text2[j-1]) {dp[i][j] = 1 + dp[i-1][j-1];}
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string ans = "";
        int i = n1, j = n2;
        while(i > 0 && j > 0) { // 1 based index=>i,j cant be 0 & starts with 1
            if(text1[i-1] == text2[j-1]) { // if char match then it must be diagonal contrib i.e dp[i][j] = 1 + dp[i-1][j-1] so move diagonally
                ans = (text1[i-1] + ans); i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) { // move up (i-1) or left(j-1) which contributed max to current cell i,j
                i--;
            }
            else {
                j--;
            }
        }
        cout<<ans;
        return ans;
    }
};
// dp[i][j] correspond to till s1[i-1] & s2[j-1] (specifically)

/*
Storing vector<vector<string>> for each index giving memory error
string longestCommonSubsequence(string text1, string text2) {
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
        return ans;
    }
*/