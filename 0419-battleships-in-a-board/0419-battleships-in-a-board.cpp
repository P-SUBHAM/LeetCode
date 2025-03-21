// Approach 1: DFS right or DFS down based on scenario
class Solution {
public:
    int cnt,M,N;
    void dfsr(vector<vector<char>>& board, int r, int c) {
        cnt++;
        for(int k = c; k < N; k++) {
            if(board[r][k] == 'X') {
                board[r][k] = '.';
            }
            else {
                break;
            }
        }
    }
    void dfsd(vector<vector<char>>& board, int r, int c) {
        cnt++;
        for(int k = r; k < M; k++) {
            if(board[k][c]=='X') board[k][c] = '.';
            else break;
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        cnt = 0; 
        int m = board.size(), n = board[0].size();
        M = m, N = n;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.') continue;
                if(board[i][j] == 'X') {
                    if(j == n-1) {
                        dfsd(board,i,j);
                    }
                    else if(i == m-1) {
                        dfsr(board,i,j);
                    }
                    else if(board[i][j+1]=='X') {
                        dfsr(board,i,j);
                    }
                    else {
                        dfsd(board,i,j);
                    }
                }

            }
        }
        return cnt;
    }
};