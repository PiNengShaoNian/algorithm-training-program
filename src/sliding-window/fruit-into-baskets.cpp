class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> kindToCnt;
    int n = fruits.size();
    int right = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      while (right + 1 < n &&
             (kindToCnt.size() <= 1 || kindToCnt.count(fruits[right + 1]))) {
        right++;
        kindToCnt[fruits[right]]++;
      }

      ans = max(ans, right - i + 1);
      kindToCnt[fruits[i]]--;
      if (kindToCnt[fruits[i]] == 0) {
        kindToCnt.erase(fruits[i]);
      }
    }
    return ans;
  }
};