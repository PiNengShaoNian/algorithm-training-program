class Solution {
 public:
  int numSteps(string s) {
    int steps = 0;
    while (s != "1") {
      steps++;
      if (s.back() == '0') {
        s.pop_back();
      } else {
        for (int i = s.size() - 1; i >= 0; i--) {
          if (s[i] == '1') {
            s[i] = '0';
            if (i == 0) {
              s = "1" + s;
              break;
            }
          } else {
            s[i] = '1';
            break;
          }
        }
      }
    }
    return steps;
  }
};