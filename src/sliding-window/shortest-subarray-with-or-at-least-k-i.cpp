class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bits(30, 0);
        auto calc = [](vector<int>& bits) -> int {
            int ans = 0;
            for (int i = 0; i < bits.size(); i++) {
                if (bits[i] > 0) {
                    ans |= 1 << i;
                }
            }
            return ans;
        };
        int ans = INT_MAX;
        for (int l = 0, r = 0; l < n; l++) {
            while (r < n && calc(bits) < k) {
                for (int i = 0; i < 30; i++) {
                    bits[i] += (nums[r] >> i) & 1;
                }
                r++;
            }

            if (calc(bits) >= k) {
                ans = min(ans, max(r - l, 1));
            }
            for (int i = 0; i < 30; i++) {
                bits[i] -= (nums[l] >> i) & 1;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};