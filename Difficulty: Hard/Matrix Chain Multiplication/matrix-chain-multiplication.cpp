//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;
    int dpf(vector<int> &arr, int i, int j) {
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1e9;
        // (i .. k) (k+1..j)
        for(int k = i; k < j; k++) {
            // arr[i] * arr[k+1] arr[k+1]*arr[j+1]
            int steps = dpf(arr,i,k) + dpf(arr,k+1,j)
                        + arr[i] * arr[k+1] * arr[j+1];
            ans = min(ans,steps);
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        // 1 2 3 4 -> A B C
        int ans = 0; ans = dpf(arr,0,n-2);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends