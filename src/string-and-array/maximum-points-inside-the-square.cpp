class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        // 每个tag到中心的最短半径
        vector<int> min1(26, 1000000001);
        int min2 = 1000000001;
        // 在所有tag中到中心最短的次短半径
        int n = s.size();
        for (int i  = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int tag = s[i] - 'a';
            int d = max(abs(x), abs(y));
            if (d < min1[tag]) {
                // d会是当前tag的最短半径，所以原来的min1[tag]可以当作次短半径的候选者了
                min2 = min(min2, min1[tag]);
                min1[tag] = d;
            } else if (d < min2) {
                // 当前tag已经有最短半径了，并且d还小于此时所有tag的次短半径，所以可以当作次短半径的候选者了
                min2 = d;
            }
        }

        int ans = 0;
        for (int d : min1) {
            if (d < min2) {
                ans++;
            }
        }
        return ans;
    }
};