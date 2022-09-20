class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rows;
    int cols;
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        for(int i = 0; i < cols; ++i) {
            if(board[0][i] == 'O') mark(0, i, board);
            if(board[rows - 1][i] == 'O') mark(rows - 1, i, board);
        }

        for(int i = 0; i < rows; ++i) {
            if(board[i][0] == 'O') mark(i, 0, board);
            if(board[i][cols - 1] == 'O') mark(i, cols - 1, board);
        }

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void mark(int row, int col, vector<vector<char>>& board) {
        board[row][col] = 'T';
        for(int i = 0; i < 4; ++i) {
            int newRow = row + dirs[i][0];
            int newCol = col + dirs[i][1];

            if(newRow >= 0 && newRow < rows &&  newCol >= 0 && newCol < cols && board[newRow][newCol] == 'O') {
                mark(newRow, newCol, board);
            }
        }
    }
};