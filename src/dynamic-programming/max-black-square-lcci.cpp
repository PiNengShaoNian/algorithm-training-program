class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // left[i][j]表示位置(i, j)及其左边有多少个连续的0
        vector<vector<int>> left(n + 1, vector<int>(n + 1));
        // up[i][j]表示位置(i, j)及其上部有多少个连续的0
        vector<vector<int>> up(n + 1, vector<int>(n + 1));
        int r = 0, c = 0, size = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == 0) {
                    left[i][j] = left[i][j - 1] + 1;
                    up[i][j] = up[i - 1][j] + 1;
                    int border = min(left[i][j], up[i][j]);
                    while (left[i - border + 1][j] < border || up[i][j - border + 1] < border) {
                        border--;
                    }
                    if (border > size) {
                        r = i - border;
                        c = j - border;
                        size = border;
                    }
                }
            }
        }
        if (size > 0) {
            return {r, c, size};
        } else {
            return {};
        }
    }
};