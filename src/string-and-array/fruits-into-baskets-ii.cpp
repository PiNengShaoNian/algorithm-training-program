class Solution {
 public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int ans = 0;
    for (int fruit : fruits) {
      int have_place = 0;
      for (int i = 0; i < baskets.size(); i++) {
        if (baskets[i] >= fruit) {
          baskets[i] = 0;
          have_place = 1;
          break;
        }
      }
      ans += !have_place;
    }
    return ans;
  }
};