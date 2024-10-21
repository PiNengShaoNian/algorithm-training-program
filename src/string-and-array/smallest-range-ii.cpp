class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[n - 1] - nums[0];
        // 1) 按升序排序数字
        // 2) 枚举分割点i，[i, n - 1]范围内的数字全减去k,[0, i - 1]范围内的数字全加上k, 这样能使数组中最大值和最小值的差值减小
        // 3) 枚举答案由于数组是有序的，经过操作后的数组在nums[i] - k > nums[0] + k的情况下最小值一定是nums[0] + k, 最大值有可能是
        //    nums[n - 1] - k或者nums[i - 1] + k
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] - k > nums[0] + k) {
                ans = min(ans, max(nums[n - 1] - k, nums[i - 1] + k) - (nums[0] + k));
                //             ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^    ^^^^^^^^^^^^
                //                     最大值                               最小值
            } else {
                ans = min(ans, max(nums[n - 1] - k, nums[i - 1] + k) - (nums[i] - k));
            }
        }
        return ans;
    }
};