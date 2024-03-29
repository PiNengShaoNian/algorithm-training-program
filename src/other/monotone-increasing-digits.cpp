/*
【思路】
从左往右遍历各位数字，找到第一个开始下降的数字[i]，将[i]减1，然后将[i+1...]各位数字全部置为9即可

例如：1232123，从左往右遍历，找到第一个开始下降的数字3，将3改为2，然后将后面所有数字全部置为9，最后为：1229999
即为答案

【需要注意一点】：如果第一个开始下降的数字[i]，前面还有与其相等的数字，需要找到最前面的一个数字作为上面所说的[i]

例如：13332，从左往右遍历，找到第一个开始下降的数字3，往前再看下，是否还有等于3的数字，找到最前面那个3，将3改为2，然后将后面的各个数字置为9，最后为：12999
*/
class Solution {
 public:
  int monotoneIncreasingDigits(int n) {
    if (n < 10) {
      return n;
    }
    string str = to_string(n);

    int i = 0;
    // 找到第一个下降的数字
    while (i + 1 < str.size() && str[i] <= str[i + 1]) {
      i++;
    }

    // 一直是上升的直接返回
    if (i == str.size() - 1) {
      return n;
    }

    // 如果前面的数字和下降的数字相同则需要取前面的
    while (i - 1 >= 0 && str[i] == str[i - 1]) {
      i--;
    }

    // 将下降的数字减一
    str[i] = (char)(str[i] - 1);
    i++;
    // 将后面的位全部置为9
    while (i < str.size()) {
      str[i] = '9';
      i++;
    }

    return stoi(str);
  }
};