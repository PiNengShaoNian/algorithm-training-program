class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。
        // 此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环.
        int n = nums.size();

        if (n == 1)
            return nums[0] == target ? 0 : -1;

        int l = 0;
        int r = n - 1;

        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);

            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[l] <= nums[mid])
            {
                if (target >= nums[l] && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] && target <= nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};