class Solution {
 public:
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    long long ans = 0l;
    int n = nums1.size();
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);

    sort(ids.begin(), ids.end(),
         [&nums2](int i, int j) -> bool { return nums2[i] > nums2[j]; });

    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0;
    for (int i = 0; i < k - 1; i++) {
      int id = ids[i];
      pq.push(nums1[id]);
      sum += nums1[id];
    }

    for (int i = k - 1; i < n; i++) {
      int id = ids[i];
      sum += nums1[id];
      pq.push(nums1[id]);

      ans = max(ans, sum * nums2[id]);

      sum -= pq.top();
      pq.pop();
    }

    return ans;
  }
};