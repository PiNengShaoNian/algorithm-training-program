class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.size();
        // count[0]表示滑动窗口中0的数量，count[1]表示滑动窗口中1的数量
        vector<int> count(2, 0);
        // 存储一个左边界为idx此时能满足k约束的最大右边界下标值
        vector<int> idxToMaxRight(n, n);
        // prefix[i]表示以[0, i-1]范围为右侧边界下标的所有符合k约束的字符串数量的个数
        vector<long long> prefix(n + 1, 0);
        int left = 0;
        for (int right = 0; right < n; right++) {
            count[s[right] - '0']++;
            while (count[0] > k && count[1] > k) {
                count[s[left] - '0']--;
                idxToMaxRight[left] = right;
                left++;
            }

            prefix[right + 1] = prefix[right] + right - left + 1;
        }

        vector<long long> res;
        for (auto &query: queries) {
            int l = query[0];
            int r = query[1];
            int realRight = min(r + 1, idxToMaxRight[l]);
            long long part1 = 1ll * (realRight - l + 1) * (realRight - l) / 2;
            long long part2 = prefix[r + 1] - prefix[realRight];
            res.push_back(part1 + part2);
        }
        return res;
    }
};