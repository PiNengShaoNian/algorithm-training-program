class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int productMax = nums[0];
        int productMin = nums[0];
        int n = nums.size();
        int ans = nums[0];
        for(int i = 1; i < n; ++i) {
            int curProductMax = max(max(productMin * nums[i], productMax * nums[i]), nums[i]);
            productMin = min(min(productMin * nums[i], productMax * nums[i]), nums[i]);
            productMax = curProductMax;
            ans = max(ans, productMax);
        } 

        return ans;
    }
};