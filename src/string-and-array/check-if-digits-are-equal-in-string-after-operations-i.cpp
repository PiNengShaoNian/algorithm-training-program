class Solution {
 public:
  bool hasSameDigits(string s) {
    string curr = s;
    while (curr.size() > 2) {
      string temp;
      for (int i = 0; i < curr.size() - 1; i++) {
        temp.push_back(((curr[i] - '0' + curr[i + 1] - '0') % 10) + '0');
      }
      curr = temp;
    }

    return curr[0] == curr[1];
  }
};