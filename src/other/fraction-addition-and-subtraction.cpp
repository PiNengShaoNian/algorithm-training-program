class Solution {
 public:
  string fractionAddition(string expression) {
    long long x = 0, y = 1;  // 分子，分母
    int index = 0, n = expression.size();

    while (index < n) {
      int sign = 1;
      if (expression[index] == '-' || expression[index] == '+') {
        sign = expression[index] == '-' ? -1 : 1;
        index++;
      }
      int x1 = 0;
      while (index < n && isdigit(expression[index])) {
        x1 = x1 * 10 + (expression[index] - '0');
        index++;
      }
      index++;  // 跳过 /

      int y1 = 0;
      while (index < n && isdigit(expression[index])) {
        y1 = y1 * 10 + (expression[index] - '0');
        index++;
      }

      x1 *= sign;

      x = x * y1 + x1 * y;
      y *= y1;
    }

    if (x == 0) {
      return "0/1";
    }

    int g = gcd(abs(x), y);
    return to_string(x / g) + "/" + to_string(y / g);
  }
};