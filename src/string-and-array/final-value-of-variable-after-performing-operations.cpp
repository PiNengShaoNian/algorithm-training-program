class Solution {
 public:
  int finalValueAfterOperations(vector<string>& operations) {
    int ans = 0;
    for (string& operation : operations) {
      ans += (operation[0] == '-' || operation[1] == '-') ? -1 : 1;
    }
    return ans;
  }
};