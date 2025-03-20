// Approach 2: backtracking
// for every row i, iterate col j 0 to n-1 and set up Q if safe and recurse and finally backtrack
class Solution {
public:
    bool safe(int r, int c, vector<string> &board, int n) {
        // actually only upper half filled so can check in that half
        for(int i = 0; i < n; i++) { // checking column vertical
            if(board[i][c] == 'Q') 
                return false;
        }
        for(int j = 0; j < n; j++) { // checking row horizontal
            if(board[r][j] == 'Q') 
                return false;
        }
        int i = r, j = c;
        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q') 
                return false;
            i--; j--;
        }
        i = r, j = c;
        while(j < n && i >= 0) {
            if(board[i][j] == 'Q') 
                return false;
            i--; j++;
        }
        return true;
    }
    void rec(int n, int i, vector<string> &board, vector<vector<string>> &ans) {
        if(i == n) { // base final case
            ans.push_back(board); // board must be valid
            return;
        }
        for(int j = 0; j < n; j++) {
            int r = i, c = j;
            if(safe(r,c,board,n)) { // if safe set and recurse and backtrack
                board[r][c] = 'Q';
                rec(n,i+1,board,ans);
                board[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        rec(n,0,board,ans);
        return ans;
    }
};

class Solution1 {
public:
    vector<string> mat;
    vector<vector<string>> ANS;
    int N;
    bool issafe(int x, int y) {
        for(int i = 0; i <= x; i++) {
            if(mat[i][y] == 'Q') return false;
        }
        int i = x, j = y;
        while(i >= 0 && j >= 0) {
            if(mat[i][j] == 'Q') return false;
            i--;j--;
        }
        i = x, j = y;
        while(i >= 0 && j < N) {
            if(mat[i][j] == 'Q') return false;
            i--;j++;
        }
        return true;
    }
    void nqueen(int row, int n) {
        if(row >= n)  {
            ANS.push_back(mat);
            return;
        }
        for(int j = 0; j < n; j++) {
            if(issafe(row,j)) {
                mat[row][j] = 'Q';
                nqueen(row+1, n);
                mat[row][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s = "";
        for(int i = 0; i < n; i++) {
            s += '.';
        }
        mat.resize(n,s);
        N = n;
        nqueen(0,n);
        return ANS;
    }
};