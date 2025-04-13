class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) {
      return 0;
    }
    sort(nums.begin(), nums.end());

    int ans = nums[1] - nums[0];
    for (int i = 1; i < n; i++) {
      ans = max(ans, nums[i] - nums[i - 1]);
    }
    return ans;
  }
};

class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
      return 0;
    }
    long long exp = 1;
    int maxVal = *max_element(nums.begin(), nums.end());
    vector<int> buf(n);

    while (maxVal >= exp) {
      vector<int> cnt(10);
      for (int i = 0; i < n; i++) {
        int digit = (nums[i] / exp) % 10;
        cnt[digit]++;
      }

      for (int i = 1; i <= 9; i++) {
        cnt[i] += cnt[i - 1];
      }

      for (int i = n - 1; i >= 0; i--) {
        int digit = (nums[i] / exp) % 10;
        buf[cnt[digit] - 1] = nums[i];
        cnt[digit]--;
      }
      copy(buf.begin(), buf.end(), nums.begin());
      exp *= 10;
    }

    int ret = 0;
    for (int i = 1; i < n; i++) {
      ret = max(ret, nums[i] - nums[i - 1]);
    }
    return ret;
  }
};