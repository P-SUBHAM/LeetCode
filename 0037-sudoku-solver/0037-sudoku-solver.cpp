// Approach 1: Backtracking
// for i,j in mat iter 1..9 check if safe rec & backtrack
// if for a cell we iter 1..9 complete then return false right away
// O(n) = (9^(n*n)) n^2 cell and each cell 1-9 pos
class Solution {
public:
    bool valid = false;
    bool safe(vector<vector<char>> &board, int i, int j, int t) {
        for(int x = 0; x < 9; x++) {
            if(board[x][j] == t) return false;
            if(board[i][x] == t) return false;
            if(board[3*(i/3)+(x/3)][3*(j/3)+(x%3)] == t) return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char t = '1'; t <= '9'; t++) {
                        if(safe(board,i,j,t)) {
                            board[i][j] = t;
                            solveSudoku(board);
                            if(valid) {
                                return;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return;
                }
            }
        }
        valid = true;
        return;
    }
};