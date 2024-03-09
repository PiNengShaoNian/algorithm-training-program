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