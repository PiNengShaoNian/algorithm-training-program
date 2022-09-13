class Solution {
public:
    //前缀积，后缀积解法
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preProduct(n + 1, 1);
        vector<int> nextProduct(n + 1, 1);
        for(int i = 1; i <= n; ++i) {
            preProduct[i] = preProduct[i - 1] * nums[i - 1];
        }

        for(int i = n - 1; i >= 0; --i) {
            nextProduct[i] = nextProduct[i + 1] * nums[i];
        }

        vector<int> ans(n);

        for(int i = 0; i < n; ++i) {
            ans[i] = preProduct[i] * nextProduct[i + 1];
        }

        return ans;
    }
    
    //优化空间版
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for(int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int R = 1;

        for(int i = n - 1; i >= 0; --i) {
            ans[i] *= R;
            R *= nums[i];
        }

        return ans;
    }
};