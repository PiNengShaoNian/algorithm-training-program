class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    vector<bool> visited(n);

    for (int i = 0; i < n; i++) {
      int cnt = 0;
      int cur = i;
      while (!visited[cur]) {
        cnt++;
        visited[cur] = true;
        cur = nums[cur];
      }

      ans = max(ans, cnt);
    }

    return ans;
  }
};