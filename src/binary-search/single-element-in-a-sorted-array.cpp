class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    // 有序全数组二分, x为单一元素下标
    // nums [1, 1, 2, 2, 3, 4, 4, 5, 5]
    // index[0, 1, 2, 3, 4, 5, 6, 7, 8]
    // 数组总长度是奇数，单一元素x左右两边数据长度都是偶数,观察单一元素左边得:
    // 如果上述比较相邻元素的结果是相等，则 mid < x，调整左边界，否则 mid ≥ x，调整右边界
    // 偶数时比较nums[mid] 和 nums[mid + 1],一样说明x在右边 调整左边界 left = mid + 1;
    // 奇数时比较nums[mid - 1] 和 nums[mid],一样说明x在右边 调整左边界 left = mid + 1;
    // 当 mid 是偶数时，mid + 1 = mid ^ 1。
    // 当 mid 是奇数时，mid - 1 = mid ^ 1。
    if (nums.size() == 1) {
      return nums[0];
    }
    int l = 0;
    int r = nums.size() - 1;
    int ans = 0;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (nums[mid ^ 1] == nums[mid]) {
        l = mid + 1;
      } else {
        ans = mid;
        r = mid - 1;
      }
    }
    return nums[ans];
  }
};