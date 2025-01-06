// Approach 1: Itterate rows, columns then Diagonals
// check All quals above != -1, else check pending with -1 then return Draw
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> board(3,vector<int>(3,-1));
        // x - 1, O - 0
        for(int i = 0; i < moves.size(); i++) {
            if(i%2==0) {board[moves[i][0]][moves[i][1]] = 1;}
            else {board[moves[i][0]][moves[i][1]] = 0;}
        }
        for(int i = 0; i < 3; i++) {
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != -1) {
                if(board[i][0] == 1) {return "A";}
                else {return "B";}
            }
        }
        for(int j = 0; j < 3; j++) {
            if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != -1) {
                if(board[0][j] == 1) {return "A";}
                else {return "B";}
            }
        }
        if((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != -1) or (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != -1)) {
            if(board[1][1] == 1) {return "A";}
            else {return "B";}
        }
        for(auto x: board) for(auto y: x) if(y == -1) return "Pending";
        return "Draw";
    }
};