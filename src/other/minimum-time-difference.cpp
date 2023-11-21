class Solution {
  int getMinutes(string& t) {
    return ((t[0] - '0') * 10 + t[1] - '0') * 60 + (t[3] - '0') * 10 +
           (t[4] - '0');
  }

 public:
  int findMinDifference(vector<string>& timePoints) {
    sort(timePoints.begin(), timePoints.end());
    int t0Minutes = getMinutes(timePoints[0]);
    int ans = INT_MAX;
    int prevMinutes = t0Minutes;
    for (int i = 1; i < timePoints.size(); i++) {
      int minutes = getMinutes(timePoints[i]);
      ans = min(ans, minutes - prevMinutes);
      prevMinutes = minutes;
    }
    ans = min(ans, t0Minutes + 1440 - prevMinutes);
    return ans;
  }
};