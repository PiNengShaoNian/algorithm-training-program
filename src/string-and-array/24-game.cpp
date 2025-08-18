class Solution {
 public:
  static constexpr int TARGET = 24;
  static constexpr double EPSILON = 1e-6;
  static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

  bool solve(vector<double>& l) {
    if (!l.size()) {
      return false;
    }

    if (l.size() == 1) {
      return fabs(l[0] - TARGET) <= EPSILON;
    }

    int size = l.size();
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (i == j) {
          continue;
        }
        vector<double> list2;
        for (int k = 0; k < size; k++) {
          if (k != i && k != j) {
            list2.push_back(l[k]);
          }
        }

        for (int op = ADD; op <= DIVIDE; op++) {
          if (op <= MULTIPLY && i > j) {
            continue;
          }
          if (op == ADD) {
            list2.push_back(l[i] + l[j]);
          } else if (op == SUBTRACT) {
            list2.push_back(l[i] - l[j]);
          } else if (op == MULTIPLY) {
            list2.push_back(l[i] * l[j]);
          } else if (op == DIVIDE) {
            list2.push_back(l[i] / l[j]);
          }
          if (solve(list2)) {
            return true;
          }
          list2.pop_back();
        }
      }
    }
    return false;
  }

  bool judgePoint24(vector<int>& cards) {
    vector<double> l;
    for (int i = 0; i < 4; i++) {
      l.push_back(static_cast<double>(cards[i]));
    }
    return solve(l);
  }
};