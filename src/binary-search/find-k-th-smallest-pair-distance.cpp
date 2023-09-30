class Solution {
 public:
  int countPairs(vector<int>& nums, int maxDis) {
    int r = -1;
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      while (r + 1 < n && nums[r + 1] - nums[i] <= maxDis) {
        r++;
      }
      cnt += r - i;
    }

    return cnt;
  }

  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = nums.back() - nums.front();
    int n = nums.size();
    int ans = 0;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      int cnt = countPairs(nums, mid);

      if (cnt >= k) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }
};