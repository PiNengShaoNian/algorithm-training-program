class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegrees(n + 1);
        vector<int> outDegrees(n + 1);

        for (auto &edge : trust) {
            int x = edge[0];
            int y = edge[1];
            outDegrees[x]++;
            inDegrees[y]++;
        }

        for (int i = 1; i <= n; i++) {
            if (inDegrees[i] == n - 1 && outDegrees[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};