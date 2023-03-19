int maxProduct(int *nums, int numsSize)
{
    int dpMin[numsSize];
    int dpMax[numsSize];

    dpMin[0] = dpMax[0] = nums[0];

#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) > (b) ? (b) : (a)
    int ans = nums[0];
    for (int i = 1; i < numsSize; ++i)
    {
        dpMax[i] = MAX(MAX(nums[i] * dpMin[i - 1], nums[i] * dpMax[i - 1]), nums[i]);
        dpMin[i] = MIN(MIN(nums[i] * dpMin[i - 1], nums[i] * dpMax[i - 1]), nums[i]);

        ans = MAX(ans, dpMax[i]);
    }

    return ans;
}