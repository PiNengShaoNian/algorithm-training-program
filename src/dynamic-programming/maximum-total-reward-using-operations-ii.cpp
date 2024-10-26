class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        if (n >= 2 && rewardValues[n - 2] == rewardValues[n - 1] - 1) {
            return rewardValues[n - 1] * 2 - 1;
        }
        bitset<100000> f0, f1;
        f0[0] = 1;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < rewardValues[i]) {
                f1[j] = f0[j];
                j++;
            }
            // 相比于问题i, 可以发现在状态的过程中可以直接将[rewardValues[i], 2 * rewardValues[i] - 1]范围内的状态直接通过位运算的方式一次性转移过来
            f0 |= f1 << rewardValues[i];
        }
        int ans = 0;
        for (int i = 0; i < f0.size(); i++) {
            if (f0[i]) {
                ans = i;
            }
        }
        return ans;
    }
};