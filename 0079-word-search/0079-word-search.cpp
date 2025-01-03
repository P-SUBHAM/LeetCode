// Approach 1: Use DFS with backtracking to check if the word exists in the grid by exploring all possible paths
class Solution {
public:
    string wordg;
    int m,n,N;
    bool dfs(vector<vector<char>> & board, int i, int j, int ind) {
        if(i < 0 or j < 0 or i >= m or j >= n or board[i][j] != wordg[ind]) {
            return false;
        }
        if(ind == N-1) {
            return true;
        }
        char temp = board[i][j];
        board[i][j] = '#';  // Mark as visited
        bool ans = dfs(board,i+1,j,ind+1) ||
                dfs(board,i,j+1,ind+1) ||
                dfs(board,i-1,j,ind+1) ||
                dfs(board,i,j-1,ind+1);
        board[i][j] = temp;  // Restore the original value
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size(), wordg = word, N = word.size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dfs(board,i,j,0)) {
                    return true;
                }
            }
        }
        return false;
    }
};