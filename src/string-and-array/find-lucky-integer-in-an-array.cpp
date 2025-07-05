class Solution {
 public:
  int findLucky(vector<int>& arr) {
    int cnt[501] = {0};

    for (int num : arr) {
      cnt[num]++;
    }

    int ans = -1;
    for (int i = 1; i <= 500; i++) {
      if (cnt[i] == i) {
        ans = max(ans, i);
      }
    }
    return ans;
  }
};