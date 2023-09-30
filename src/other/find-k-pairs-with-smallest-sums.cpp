class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    auto cmp = [&nums1, &nums2](const pair<int, int>& a,
                                const pair<int, int>& b) {
      return nums1[a.first] + nums2[a.second] >
             nums1[b.first] + nums2[b.second];
    };

    int m = nums1.size();
    int n = nums2.size();
    vector<vector<int>> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);

    for (int i = 0; i < m; i++) {
      pq.push({i, 0});
    }

    for (int i = 0; i < k && pq.size(); i++) {
      auto [x, y] = pq.top();
      pq.pop();
      ans.push_back({nums1[x], nums2[y]});

      if (y + 1 < n) {
        pq.push({x, y + 1});
      }
    }

    return ans;
  }
};