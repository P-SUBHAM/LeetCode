//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
// Approach 1: Floyd Warshall
// for every i j take rnd k(0..N) and relax edged
// O(N^3)
class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        int N = mat.size(), inf = 1e8;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(mat[i][j] == -1) {
                    mat[i][j] = inf;
                }
            }
        }
        for(int k = 0; k < N; k++) { // main logic floyd Warshall
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(mat[i][k] != inf && mat[k][j] != inf) {
                        mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);
                    }
                }
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(mat[i][j] == inf) {
                    mat[i][j] = -1;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends