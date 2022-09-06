class TicTacToe {
public:
    vector<int> cols;
    vector<int> rows;
    int dia1 = 0;
    int dia2 = 0;
    int N;

    TicTacToe(int n) {
        cols = vector<int>(n, 0);
        rows = vector<int>(n, 0);
        N = n;
    }

    int move(int row, int col, int player) {
        int value = player == 1 ? -1 : 1;

        rows[row] += value;
        cols[col] += value;

        if(row == col) {
            dia1 += value;
        }

        if(row + col + 1 == N) {
            dia2 += value;
        }

        if(rows[row] == N || cols[col] == N || dia1 == N || dia2 == N) {
            return 2;
        }

        if(rows[row] == -N || cols[col] == -N || dia1 == -N || dia2 == -N) {
            return 1;
        }

        return 0;   
    }
};

//直接用之前design-tic-tac-toe的代码模拟解题
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        TicTacToe ttt(3);
        int n = moves.size();
        int lastState = 0;
        for(int i = 0; i < n; ++i) {
            auto& move = moves[i];
            lastState = ttt.move(move[0], move[1], i % 2 == 0 ? 1 : 2);
        }

        return lastState == 1 ? "A" : lastState == 2 ? "B" : (lastState == 0 && n == 9) ? "Draw" : "Pending";
    }
};