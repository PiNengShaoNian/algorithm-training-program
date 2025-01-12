class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        auto maxlen = [&](int k) -> int {
            int ans = 0;
            for (int i = 0; i < candidates.size(); i++) {
                if (candidates[i] & (1 << k)) {
                    ans++;
                }
            }
            return ans;
        };

        int ans = 0;
        for (int i = 0; i < 24; i++) {
            ans = max(ans, maxlen(i));
        }
        return ans;
    }
};