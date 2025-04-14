//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<vector<int>> dp;
    int dpf(int n, int k) {
        if(k == 0) {
            return 0;
        }
        if(n == 1) {
            return k;
        }
        if(dp[n][k] != -1) return dp[n][k];
        int ans = k+1;
        for(int i = 1; i <= k; i++) {
            int breaks = dpf(n-1,i-1);
            int notBreak = dpf(n,k-i);
            ans = min(ans,1+max(breaks,notBreak));
        }
        return dp[n][k] = ans;
    }
    int eggDropBS(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= k; i++) dp[1][i] = i;

        for (int e = 2; e <= n; e++) {
            for (int f = 1; f <= k; f++) {
                int low = 1, high = f;
                int ans = f;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    int breaks = dp[e - 1][mid - 1];
                    int notBreak = dp[e][f - mid];
                    int worst = 1 + max(breaks, notBreak);
                    if (breaks > notBreak) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                    ans = min(ans, worst);
                }
                dp[e][f] = ans;
            }
        }
        return dp[n][k];
    }
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k) {
        // code here
        return eggDropBS(n,k);
        dp.resize(n+1,vector<int>(k+1,k+1));
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 1; j <= k; j++) dp[1][j] = j;
        
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                for(int l = 1; l <= j; l++) {
                    int breaks = dp[i-1][l-1];
                    int notBreak = dp[i][j-l];
                    dp[i][j] = min(dp[i][j],1+max(breaks,notBreak));
                }
            }
        }
        return dp[n][k];
    }
};


//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends