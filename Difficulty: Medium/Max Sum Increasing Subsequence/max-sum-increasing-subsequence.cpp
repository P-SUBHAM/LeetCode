//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dpf(vector<int>& arr, int i, vector<int> &dp) {
        int ans = arr[i], n = arr.size();
        if(i == n-1) return arr[i];
        if(dp[i] != -1) return dp[i];
        for(int j = i+1; j < n; j++) {
            if(arr[j] > arr[i]) {
                ans = max(ans,arr[i]+dpf(arr,j,dp));
            }
        }
        return dp[i] = ans;
    }
    int maxSumIS(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        vector<int> dp(n+1,-1);
        for(int i = 0; i < n; i++) {
            ans = max(ans,dpf(arr,i,dp));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxSumIS(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends