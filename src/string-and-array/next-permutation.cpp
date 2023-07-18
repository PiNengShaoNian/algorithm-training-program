class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        // 要求这样的一个序列要根据当前nums组成的一个数字，找出一个新的
        // 数字排列组成的数字比该数字更大，但是增大的幅度又是最小的
        // 比如123456的下一个较大的数字是123465而不是123654
        // 要使增大的幅度最小，需要在i位置找到一个数字，并在j位置找到
        // 第二个数字并且nums[i] < nums[j]且该i位置是最靠后的，这样交换后
        // 我们就得到的一个较大的数, 此时虽然得到了一个较大的数但是他增大的幅度并不是
        // 最小的要是他的增幅最小我们可以自傲交换i和j后对数组的nums[i+1:]部分进行升序排序即可
        
        // 枚举i位置，从后往前枚举能保证他是最靠后的
        for (int i = n - 2; i >= 0; --i)
        {
            int big = INT_MAX;
            int big_idx = -1;
            // 枚举j位置
            for (int j = i + 1; j < n; ++j)
            {
                // 保证j位置的数比i大，且是所有满足条件中最小的
                if (nums[j] > nums[i] && nums[j] < big)
                {
                    big = nums[j];
                    big_idx = j;
                }
            }

            // 找到了符合交换条件的数字
            if (big_idx != -1)
            {
                int tmp = nums[i];
                nums[i] = nums[big_idx];
                nums[big_idx] = tmp;
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }

        // 没有更大的数字了，进行升序排序循环到最小的数字
        sort(nums.begin(), nums.end(), [](int a, int b) -> bool
             { return a < b; });
    }
};