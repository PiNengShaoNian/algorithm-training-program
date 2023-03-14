int lengthOfLIS(int* nums, int numsSize){
    int *dp = malloc(numsSize * sizeof(int));
    dp[0] = 1;
    int ans = 1;
    #define MAX(a, b) (a) > (b) ? (a) : (b)
    for(int i = 1; i < numsSize; ++i) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                dp[i] = MAX(dp[i], dp[j] + 1);
            }
        }

        ans = MAX(dp[i], ans);
    }

    return ans;
}