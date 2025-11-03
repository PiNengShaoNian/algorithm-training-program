class Solution {
 public:
  int minCost(string colors, vector<int>& neededTime) {
    int max_time = neededTime[0];
    char color = colors[0];
    int ans = max_time;
    int n = colors.size();

    for (int i = 1; i < n; i++) {
      if (colors[i] != color) {
        ans -= max_time;
        color = colors[i];
        max_time = neededTime[i];
      } else {
        max_time = max(max_time, neededTime[i]);
      }

      ans += neededTime[i];
    }

    ans -= max_time;

    return ans;
  }
};