class Solution {
 public:
  long long minTime(vector<int>& skill, vector<int>& mana) {
    int n = skill.size();
    vector<long long> lastFinish(n);  // 第 i 名巫师完成上一瓶药水的时间
    for (int m : mana) {
      long long sum_t = 0;
      for (int i = 0; i < n; i++) {
        sum_t = max(sum_t, lastFinish[i]) + skill[i] * m;
      }
      lastFinish[n - 1] = sum_t;
      for (int i = n - 2; i >= 0; i--) {
        lastFinish[i] = lastFinish[i + 1] - skill[i + 1] * m;
      }
    }

    return lastFinish[n - 1];
  }
};