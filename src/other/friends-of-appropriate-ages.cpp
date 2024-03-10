class Solution {
 public:
  int numFriendRequests(vector<int>& ages) {
    int n = ages.size();
    sort(ages.begin(), ages.end());
    // 0.5 * ages[x] + 7 < ages[y] <= ages[x]
    // 要满足上述表达式ages[x]的值至少为15
    int left = 0, right = 0, ans = 0;
    for (int age : ages) {
      if (age < 15) {
        continue;
      }

      // 当ages[x]取值为age时，ages[y]能取的最左边
      while (ages[left] <= 0.5 * age + 7) {
        left++;
      }

      // 当ages[x]取值为age时, ages[y]能取的最右边
      while (right + 1 < n && ages[right + 1] <= age) {
        right++;
      }
      ans += right - left;
    }
    return ans;
  }
};

class Solution {
 public:
  int numFriendRequests(vector<int>& ages) {
    vector<int> cnt(121);
    for (int age : ages) {
      cnt[age]++;
    }
    vector<int> pre(121);
    for (int i = 1; i < 121; i++) {
      pre[i] = pre[i - 1] + cnt[i];
    }
    int ans = 0;
    for (int i = 15; i <= 120; i++) {
      if (cnt[i]) {
        int bound = i * 0.5 + 8;
        ans += cnt[i] * (pre[i] - pre[bound - 1] - 1);
      }
    }
    return ans;
  }
};