class Solution {
public:
    long long minEnd(int n, int x) {
        // 要想数组所有元素&之后的值是x，那么改升序数组中可能的最小值就是x本身
        // 要想该数组第n - 1位数字的最小值只需要在x的基础上`插入`数字的(n - 1)的二进制表示即可
        // 为了保证&的结果为x，且让数字尽可能地小我们在插入时可以只在x的0bit位上依次插入
        // n - 1的二进制位表示
        int bitCount = 64 - __builtin_clz(n) - __builtin_clz(x);
        long long res = x;
        long long m = n - 1;
        int j = 0;
        for (int i = 0; i < bitCount; i++) {
            if (((res >> i) & 1) == 0) {
                if ((m >> j) & 1) {
                    res |= (1LL << i);
                }
                j++;
            }
        }
        return res;
    }
};