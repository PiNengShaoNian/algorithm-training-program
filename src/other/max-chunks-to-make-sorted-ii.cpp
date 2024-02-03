class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    unordered_map<int, int> cnt;
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x = arr[i];
      int y = sortedArr[i];
      cnt[x]++;
      if (cnt[x] == 0) {
        cnt.erase(x);
      }
      cnt[y]--;
      if (cnt[y] == 0) {
        cnt.erase(y);
      }
      // arr和排序后的arr在一段中数字的频次相同，该段可分为一个单独的段
      if (cnt.size() == 0) {
        ans++;
      }
    }
    return ans;
  }
};