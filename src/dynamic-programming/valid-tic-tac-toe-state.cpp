class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;
        for (string & row : board) {
            for (char c : row) {
                xCount = (c == 'X') ? (xCount + 1) : xCount;
                oCount = (c == 'O') ? (oCount + 1) : oCount;
            }
        }
        return !((oCount != xCount && oCount != xCount - 1) ||
               (oCount != xCount - 1 && win(board, 'X')) ||
               (oCount != xCount && win(board, 'O')));
    }

    bool win(vector<string>& board, char p) {
        for (int i = 0; i < 3; ++i) {
            if ((p == board[0][i] && p == board[1][i] && p == board[2][i]) ||
               (p == board[i][0] && p == board[i][1] && p == board[i][2])) {
                return true;
            }
        }
        return ((p == board[0][0] && p == board[1][1] && p == board[2][2]) ||
                (p == board[0][2] && p == board[1][1] && p == board[2][0]));
    }
};