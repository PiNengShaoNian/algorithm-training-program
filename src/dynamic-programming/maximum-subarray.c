int maxSubArray(int* nums, int numsSize){
    int* dp = malloc(sizeof(int) * numsSize);
    
    int ans = nums[0];
    dp[0] = nums[0];
    for(int i = 1; i < numsSize; ++i) {
        dp[i] = nums[i];

        if(dp[i - 1] + nums[i] > nums[i]) {
            dp[i] = dp[i - 1] + nums[i];
        }

        ans = ans > dp[i] ? ans : dp[i];
    }

    return ans;
}