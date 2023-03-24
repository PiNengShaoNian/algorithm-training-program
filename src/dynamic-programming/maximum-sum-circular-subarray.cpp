class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpMax(n);
        vector<int> dpMin(n);
        int maxSum, minSum, sum; 
        sum = maxSum = minSum = dpMax[0] = dpMin[0] = nums[0];


        for(int i = 1; i < n; ++i) {
            dpMax[i] = max(dpMax[i - 1] + nums[i], nums[i]);
            dpMin[i] = min(dpMin[i - 1] + nums[i], nums[i]);
            sum += nums[i];
            maxSum = max(maxSum, dpMax[i]);
            minSum = min(minSum, dpMin[i]);
        }

        return max(maxSum, sum - minSum == 0 ? maxSum : sum - minSum);
    }
};

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& _nums) {
        vector<int> nums(_nums.begin(), _nums.end());
        int n = _nums.size();

        for(int i = 0; i < n; ++i) {
            nums.push_back(_nums[i]);
        }

        vector<int> presum(2 * n + 1, 0);

        presum[0] = 0;

        for(int i = 1; i <= 2 * n; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }

        deque<int> dq;
        int ans = nums[0];
        for(int i = 0; i <= 2 * n; ++i) {
            while(dq.size() && i - dq.front() >= n + 1) dq.pop_front();

            if(dq.size())
                ans = max(ans, presum[i] - presum[dq.front()]);

            while(dq.size() && presum[dq.back()] >= presum[i]) dq.pop_back();

            dq.push_back(i);
        }

        return ans;
    }
};