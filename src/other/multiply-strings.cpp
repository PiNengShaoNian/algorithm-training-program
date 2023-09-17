class Solution {
 public:
  string multiply(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    vector<int> ans(len1 + len2);

    for (int i = len1 - 1; i >= 0; i--) {
      for (int j = len2 - 1; j >= 0; j--) {
        int product = (num1[i] - '0') * (num2[j] - '0');
        int sum = product + ans[i + j + 1];
        ans[i + j + 1] = sum % 10;
        ans[i + j] += sum / 10;
      }
    }

    string num;
    bool first = true;
    for (int i = 0; i < ans.size(); i++) {
      if (first && ans[i] == 0) {
        continue;
      }
      num += to_string(ans[i]);
      first = false;
    }

    return num.size() ? num : "0";
  }
};