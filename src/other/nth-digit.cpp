class Solution {
 public:
  int findNthDigit(int n) {
    int low = 1, high = 9;
    while (low < high) {
      int mid = (high - low) / 2 + low;
      if (totalDigits(mid) < n) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    /**
     * 输入：n = 11
     * 输出：0
     * 解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10
     * 的一部分。
     * 
     * d = 2 在该数字序列中第11位数字最多只需要到数字长度位2数字即可构成
     * prevDigits = 9 长度为1的数字总共有9个数字长度(1,2,3,...,8,9)
     * index = 1 数位n在长度为2的数字中组成的数位序列中处于第index(从零开始)即101112....中的第1位即为0
     * start = 10 在长度为2的数字中第0个数字为10
     * num = 10 用start + (index / d)即可计算出n数位处于长度为2的数字中的第几个其中处于index个数位下标(index / d)即为他的数字下标
     * digitIndex = 1, 计算出n位数处于num中的第几位计算得到他为数字10中的第1位
     * digit = 0, 由于digitIndex中是以大端序表示的，其小端序的实际index为d - digitIndex - 1
     */
    int d = low;
    int prevDigits = totalDigits(d - 1);
    int index = n - prevDigits - 1;
    int start = (int)pow(10, d - 1);
    int num = start + index / d;
    int digitIndex = index % d;
    int digit = (num / (int)(pow(10, d - digitIndex - 1))) % 10;
    return digit;
  }

  int totalDigits(int length) {
    int digits = 0;
    int curLength = 1, curCount = 9;
    while (curLength <= length) {
      digits += curLength * curCount;
      curLength++;
      curCount *= 10;
    }
    return digits;
  }
};