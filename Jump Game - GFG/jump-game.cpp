// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  map<int,bool> dp;
    bool jumpGame(vector<int> v, int i, int n) {
        if(i == n-1 || i + v[i] >= n-1) {
            return dp[i] = true;
        }
        if(dp.find(i) != dp.end()) {
            return dp[i];
        }
        bool ans = false;
        for(int j = 1; j <= v[i] && i+j < n; j++) {
            ans = ans || jumpGame(v,i+j,n);
        }
        return dp[i] = ans;
    }
    int canReach(int A[], int N) {
        // code here
        vector<int> v;
        for(int i = 0; i < N; i++) {
            v.push_back(A[i]);
        }
        return jumpGame(v,0,N);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends