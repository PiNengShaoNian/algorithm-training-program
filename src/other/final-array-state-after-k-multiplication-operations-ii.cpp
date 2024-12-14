class Solution {
    const int MOD = 1'000'000'007;

    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return move(nums);
        }

        int n = nums.size();
        int mx = ranges::max(nums);
        vector<pair<long long, int>> h(n);
        for (int i = 0; i < n; i++) {
            h[i] = {nums[i], i};
        }
        ranges::make_heap(h, greater<>());

        for (; k && h[0].first < mx; k--) {
            ranges::pop_heap(h, greater<>());
            h.back().first *= multiplier;
            ranges::push_heap(h, greater<>());
        }

        ranges::sort(h);
        for (int i = 0;i < n; i++) {
            auto &[x, j] = h[i];
            nums[j] = x % MOD * pow(multiplier, k / n + (i < k % n)) % MOD;
        }
        return move(nums);
    }
};