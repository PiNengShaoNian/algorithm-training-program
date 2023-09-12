class Solution {
 public:
  vector<int> minInterval(vector<vector<int>>& intervals,
                          vector<int>& queries) {
    // https://leetcode.cn/problems/minimum-interval-to-include-each-query/solutions/755628/bao-han-mei-ge-cha-xun-de-zui-xiao-qu-ji-e21j/comments/2068221
    vector<int> qindex(queries.size());
    iota(qindex.begin(), qindex.end(), 0);
    sort(qindex.begin(), qindex.end(),
         [&](int a, int b) -> bool { return queries[a] < queries[b]; });
    sort(intervals.begin(), intervals.end(),
         [](const vector<int>& a, const vector<int>& b) -> bool {
           return a[0] < b[0];
         });

    priority_queue<vector<int>> pq;

    vector<int> ans(queries.size(), -1);
    int i = 0;
    for (int q : qindex) {
      while (i < intervals.size() && intervals[i][0] <= queries[q]) {
        int l = intervals[i][1] - intervals[i][0] + 1;
        pq.push({-l, intervals[i][0], intervals[i][1]});
        i++;
      }

      while (pq.size() && pq.top()[2] < queries[q]) {
        pq.pop();
      }

      if (pq.size()) {
        ans[q] = -pq.top()[0];
      }
    }
    return ans;
  }
};