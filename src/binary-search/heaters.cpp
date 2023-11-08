class Solution {
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    int ans = 0;
    sort(heaters.begin(), heaters.end());
    for (int house : houses) {
      int j =
          upper_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
      int i = j - 1;
      int rightDis = j == heaters.size() ? INT_MAX : heaters[j] - house;
      int leftDis = i < 0 ? INT_MAX : house - heaters[i];
      ans = max(ans, min(rightDis, leftDis));
    }
    return ans;
  }
};