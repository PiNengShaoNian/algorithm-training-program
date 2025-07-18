class Solution {
 public:
  long long minimumDifference(vector<int>& nums) {
    int m = nums.size(), n = m / 3;
    priority_queue<int, vector<int>, greater<>> min_pq(nums.end() - n,
                                                       nums.end());
    long long sum = reduce(nums.end() - n, nums.end(), 0LL);

    vector<long long> suf_max(m - n + 1);
    suf_max[m - n] = sum;
    for (int i = m - n - 1; i >= n; i--) {
      int v = nums[i];
      if (nums[i] > min_pq.top()) {
        sum += v - min_pq.top();
        min_pq.pop();
        min_pq.push(v);
      }
      suf_max[i] = sum;
    }

    priority_queue<int> max_pq(nums.begin(), nums.begin() + n);
    long long pre_min = reduce(nums.begin(), nums.begin() + n, 00L);

    long long ans = pre_min - suf_max[n];
    for (int i = n; i < m - n; i++) {
      int v = nums[i];
      if (v < max_pq.top()) {
        pre_min += v - max_pq.top();
        max_pq.pop();
        max_pq.push(v);
      }
      ans = min(ans, pre_min - suf_max[i + 1]);
    }
    return ans;
  }
};