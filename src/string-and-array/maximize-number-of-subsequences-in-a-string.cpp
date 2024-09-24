class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long ans = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for (char c : text) {
            if (c == pattern[1]) {
                ans += cnt1;
                cnt2++;
            }
            if (c == pattern[0]) {
                cnt1++;
            }
        }
        // 可以额外加一个字符，我们可以考虑一下两种情况
        // 1) 加入pattern[0]到头部，可以和字符串中的所有pattern[1]字符组成子序列
        // 2) 加入pattern[1]到尾部，可以和字符串中所有的pattern[0]字符组成子序列
        return ans + max(cnt1, cnt2);
    }
};