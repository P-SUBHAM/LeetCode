// Approach 1: Floyd Warshall
// for every i j take rnd k(0..N) and relax edges k..i..j
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
        // k,i,j loop order matter
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
