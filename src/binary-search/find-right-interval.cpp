class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<pair<int, int>> startIntervals;
    int n = intervals.size();
    for (int i = 0; i < n; i++) {
      startIntervals.emplace_back(intervals[i][0], i);
    }
    sort(startIntervals.begin(), startIntervals.end());

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
      auto it = lower_bound(startIntervals.begin(), startIntervals.end(),
                            make_pair(intervals[i][1], 0));
      if (it != startIntervals.end()) {
        ans[i] = it->second;
      }
    }
    return ans;
  }
};