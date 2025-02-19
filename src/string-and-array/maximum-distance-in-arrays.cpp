class Solution {
    public:
        int maxDistance(vector<vector<int>>& arrays) {
            int res = 0;
            int max_val = arrays[0].back();
            int min_val = arrays[0][0];
            for (int i = 1; i < arrays.size(); i++) {
                res = max(res, max(abs(max_val - arrays[i][0]), abs(arrays[i].back() - min_val)));
                max_val = max(max_val, arrays[i].back());
                min_val = min(min_val, arrays[i][0]);
            }
            return res;
        }
    };