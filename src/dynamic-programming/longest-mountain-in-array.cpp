class Solution {
 public:
  int longestMountain(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n);
    for (int i = 1; i < n; i++) {
      if (arr[i] > arr[i - 1]) {
        left[i] = 1 + left[i - 1];
      }
    }

    vector<int> right(n);
    for (int i = n - 2; i >= 0; i--) {
      if (arr[i] > arr[i + 1]) {
        right[i] = 1 + right[i + 1];
      }
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      if (left[i] && right[i]) {
        ans = max(ans, left[i] + right[i] + 1);
      }
    }
    return ans;
  }
};