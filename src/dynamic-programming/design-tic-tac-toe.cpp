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

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */