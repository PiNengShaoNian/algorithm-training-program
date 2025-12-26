class Solution {
 public:
  int bestClosingTime(string customers) {
    int penalty = 0, min_penalty = 0, ans = 0;
    for (int i = 0; i < customers.size(); i++) {
      penalty += customers[i] == 'N' ? 1 : -1;
      if (penalty < min_penalty) {
        min_penalty = penalty;
        ans = i + 1;
      }
    }
    return ans;
  }
};