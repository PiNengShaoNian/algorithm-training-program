class Solution {
public:
    unordered_map<int, int> dp;

    int find(int cur) {
        if(!dp.count(cur)) {
            return -1;
        }
        else {
            int ans = dp[cur];
            if(ans != -1) return ans;
            int len = find(cur - 1);

            ans = len == -1 ? 1 : 1 + len;
            return dp[cur] = ans;
        }
    }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        //建图
        for(int i = 0; i < n; ++i) {
            dp[nums[i]] = -1;
        }

        //图遍历，加路径压缩
        for(int i = 0; i < n; ++i) {
            int len = find(nums[i]);
            ans = max(ans, len);
        }

        return ans;
    }
};