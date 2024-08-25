class Solution {
 public:
  vector<int> splitIntoFibonacci(string num) {
    vector<int> list;
    backtrack(list, num, num.size(), 0, 0, 0);
    return list;
  }

  bool backtrack(vector<int> &list, string &num, int len, int index,
                 long long sum, long long prev) {
    if (index == len) {
      return list.size() >= 3;
    }
    long long curr = 0;
    for (int i = index; i < len; i++) {
      // 如果遇到前缀零数字返回
      if (i > index && num[index] == '0') {
        break;
      }

      curr = curr * 10 + num[i] - '0';
      // 遇到大与32为整数的数字返回
      if (curr > INT_MAX) {
        break;
      }

      // 已经有两个数字了，开始校验和
      if (list.size() >= 2) {
        if (curr < sum) {
          continue;
        } else if (curr > sum) {
          break;
        }
      }

      list.push_back(curr);
      if (backtrack(list, num, len, i + 1, prev + curr, curr)) {
        return true;
      }
      list.pop_back();
    }
    return false;
  }
};
