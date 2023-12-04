class Solution {
 public:
  string solveEquation(string equation) {
    int sign1 = 1;
    int index = 0;
    int n = equation.size();
    int val = 0;
    int factor = 0;

    while (index < n) {
      if (equation[index] == '=') {
        sign1 = -1;
        index++;
        continue;
      }

      int sign2 = sign1;
      if (equation[index] == '-' || equation[index] == '+') {
        sign2 = equation[index] == '-' ? -sign2 : sign2;
        index++;
      }

      int valid = false;
      int num = 0;
      while (index < n && isdigit(equation[index])) {
        num *= 10;
        num += equation[index] - '0';
        index++;
        valid = true;
      }

      if (equation[index] == 'x') {
        factor += valid ? sign2 * num : sign2;
        index++;
      } else {
        val += sign2 * num;
      }
    }

    if (factor == 0) {
      return val == 0 ? "Infinite solutions" : "No solution";
    }

    return "x=" + to_string(-val / factor);
  }
};