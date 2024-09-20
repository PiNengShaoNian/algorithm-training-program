class Solution {
public:
    unordered_map<int, int> memo;
    int countSpecialNumbers(int n) {
        string nStr = to_string(n);
        int res = 0;
        int prod = 9;
        // 先算出位数小于n的特殊整数数量
        for (int i = 0; i < nStr.size() - 1; i++) {
            res += prod;
            prod *= 9 - i;
        }
        res += dp(0, false, nStr);
        return res;
    }

    // mask表示已经选取了的数字(如果mask的第i为bit有值说明数字i已被选取)
    // prefixSmaller当前选取的所有数字组成的前缀是否小于n的前缀
    int dp(int mask, bool prefixSmaller, const string &nStr) {
        // 退出条件返回1
        if (__builtin_popcount(mask) == nStr.size()) {
            return 1;
        }

        // 用一个数字来存储mask和prefixSmaller来组成一个缓存key
        int key = mask * 2 + (prefixSmaller ? 1 : 0);
        if (!memo.count(key)) {
            int res = 0;
            // 如果mask为1说明我们在为前缀的第一位选取数字，此时最小只能从1开始
            int lowerBound = mask == 0 ? 1 : 0;
            // 如果当前组成的前缀小于n的前缀那么此时我们可选的数字最大的范围可以是9
            // 反之则是当前n的第k位的大小, 其中k为已经组成前缀的长度
            int upperBound = prefixSmaller ? 9 : nStr[__builtin_popcount(mask)] - '0';
            for (int i = lowerBound; i <= upperBound; i++) {
                // 判断该数字有没有北选取
                if (((mask >> i) & 1) == 0) {
                    res += dp(mask | (1 << i), prefixSmaller || i < upperBound, nStr);
                }
            }
            memo[key] = res;
        }
        return memo[key];
    }
};