class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l = 0;
        int r = n - 1;
        int t = 0;
        int b = n - 1;
        int max = n * n;
        int cur = 1;
        vector<vector<int>> ans(n, vector<int>(n));
        while (cur <= max) {
            for (int i = l; i <= r; i++) {
                ans[t][i] = cur++;
            }
            t++;

            for (int i = t; i <= b; i++) {
                ans[i][r] = cur++;
            }
            r--;

            for (int i = r; i >= l; i--) {
                ans[b][i] = cur++;
            }
            b--;

            for (int i = b; i >= t; i--) {
                ans[i][l] = cur++;
            }
            l++;
        }
        return ans;
    }
};