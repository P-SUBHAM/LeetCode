//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int dpf(vector<int> &price, int ind, int N, 
    vector<vector<int>> &dp) {
        if(N < 0) return INT_MIN;
        if(ind == 0) {
            return N * price[0];
        }
        if(dp[ind][N] != -1) return dp[ind][N];
        int notTake = dpf(price,ind-1,N,dp);
        int rodLength = ind + 1;
        int take = price[ind] + dpf(price,ind,N-rodLength,dp);
        return dp[ind][N] = max(take,notTake);
    }
    int recursionDp(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1)); // ind0-n-1,len0-n
        return dpf(price,n-1,n,dp);
        return 0;
    }
    int iterativeDP(vector<int> &price) {
        return 0;
    }
    int dp2arr(vector<int> &price) {
        return 0;
    }
    int dp1arr(vector<int> &price) {
        return 0;
    }
    int cutRod(vector<int> &price) {
        return recursionDp(price);
        return iterativeDP(price);
        return dp2arr(price);
        return dp1arr(price);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends