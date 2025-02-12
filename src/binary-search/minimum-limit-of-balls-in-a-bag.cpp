class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int ops = 0;
            for (int num : nums) {
                ops += (num - 1) / mid;
            }
            if (ops <= maxOperations) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};