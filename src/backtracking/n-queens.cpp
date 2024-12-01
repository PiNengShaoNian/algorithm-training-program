class Solution {
public:
    vector<int> rows;
    vector<int> cols;
    vector<int> placement;
    unordered_map<int, int> dia1;
    unordered_map<int, int> dia2;
    int n;

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        rows = vector<int>(n, 0);
        cols = vector<int>(n, 0);
        placement = vector<int>(n, 0);
        dia1.clear();
        dia2.clear();

        vector<vector<string>> ans;
        dfs(ans, 0);
        return ans;
    }

    void generateBoard(vector<vector<string>> &ans) {
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string row(n, '.');
            row[placement[i]] = 'Q';
            board.emplace_back(row);
        }
        ans.emplace_back(board);
    }

    void dfs(vector<vector<string>> &ans, int i) {
        if (i == n) {
            generateBoard(ans);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (!rows[i] && !cols[j] && !dia1[i - j] && !dia2[i + j]) {
                rows[i] = cols[j] = dia1[i - j] = dia2[i + j] = 1;
                placement[i] = j;
                dfs(ans, i + 1);
                rows[i] = cols[j] = dia1[i - j] = dia2[i + j] = 0;
            }
        }
    }
};