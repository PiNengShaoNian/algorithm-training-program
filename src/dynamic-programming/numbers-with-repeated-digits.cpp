class Solution {
public:
     int f[10][10];
     Solution() {
        for (int i = 1; i < 10; i++) {
            for (int j = i; j < 10; j++) {
                int cur = 1;
                for (int k = i; k <= j; k++) cur *= k;
                f[i][j] = cur;
            }
        }
     }
     int dp(int x) {
        int t = x;
        vector<int> nums;
        while (t != 0) {
            nums.push_back(t % 10);
            t /= 10;
        }
        int n = nums.size();
        if (n <= 1) return x + 1; // [0, 9]
        // 位数和 x 相同（res1 + res2）
        int ans = 0;
        for (int i = n - 1, p = 1, s = 0; i >= 0; i--, p++) {
            int cur = nums[i], cnt = 0;
            for (int j = cur - 1; j >= 0; j--) {
                if (i == n - 1 && j == 0) continue;
                if (((s >> j) & 1) == 0) cnt++;
            }
            int a = 10 - p, b = a - (n - p) + 1;
            ans += b <= a ? cnt * f[b][a] : cnt;
            if (((s >> cur) & 1) == 1) break;
            s |= (1 << cur);
            if (i == 0) ans++;
        }
        // 位数比 x 少（res3）
        ans += 10;
        for (int i = 2, last = 9; i < n; i++) {
            int cur = last * (10 - i + 1);
            ans += cur; last = cur;
        }
        return ans;
    }
    int numDupDigitsAtMostN(int n) {
        return (n + 1) - dp(n);
    }
};