class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(), cards.end());

        int ans = 0;
        int tmp = 0;
        int odd, even = -1;
        int end = cards.size() - cnt;
        // 贪心的去除最大的cnt个数
        for (int i = cards.size() - 1; i >= end; i--) {
            tmp += cards[i];
            if (cards[i] & 1) {
                odd = cards[i];
            } else {
                even = cards[i];
            }
        }

        // 已经是偶数直接返回
        if (!(tmp & 1)) {
            return tmp;
        }

        // 如果不是偶数就从剩下的数中挑出一个最大的偶数和已挑选的最小的奇数做替换
        // 和从剩下的数中挑出一个最大的奇数和已挑选的最小的偶数做替换
        // 两者取其大
        for (int i = cards.size() - cnt - 1; i >= 0; i--) {
            if (cards[i] & 1) {
                if (even != -1) {
                    ans = max(ans, tmp - even + cards[i]);
                }
            } else {
                if (odd != -1) {
                    ans = max(ans, tmp - odd + cards[i]);
                }
            }
        }

        return ans;
    }
};