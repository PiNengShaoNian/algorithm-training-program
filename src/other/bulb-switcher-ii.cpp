class Solution {
 public:
  int flipLights(int n, int presses) {
    unordered_set<int> seen;
    // 按钮的点按顺序，和偶数次的点按次数对结果没有影响
    // 所以只需要关注某个按钮是点击了奇数次还是偶数次

    // 按照会受到按钮影响分类，这n个灯可分为4组
    // 6k + 1，受到1,3,4影响
    // 6k + 2, 6k + 6, 受到1,2影响
    // 6k + 3, 6k + 5, 受到1,3影响
    // 6k + 4, 受到1,2,4影响

    // 直接在这里枚举这四个按钮最终奇偶状态,
    // pressArr[i]为1代表i按钮点了奇数次，否则就是点了偶数次
    for (int i = 0; i < 1 << 4; i++) {
      vector<int> pressArr(4);
      for (int j = 0; j < 4; j++) {
        pressArr[j] = (i >> j) & 1;
      }
      // 当前的按钮最终点按状态中，有几个按钮处于按下状态
      int sum = accumulate(pressArr.begin(), pressArr.end(), 0);
      // 排除掉不可能的状态,
      // 即sum为偶数时，其presses必定也是偶数，并且sum一定得小于presses
      if (sum % 2 == presses % 2 && sum <= presses) {
        // 获得第一组灯泡的状态
        int status = pressArr[0] ^ pressArr[2] ^ pressArr[3];
        // 获得第二组灯泡的状态
        if (n >= 2) {
          status |= (pressArr[0] ^ pressArr[1]) << 1;
        }
        // 获得第三组灯泡的状态
        if (n >= 3) {
          status |= (pressArr[0] ^ pressArr[2]) << 2;
        }
        // 获得第四组灯泡的状态
        if (n >= 4) {
          status |= (pressArr[0] ^ pressArr[1] ^ pressArr[3]) << 3;
        }
        seen.emplace(status);
      }
    }
    return seen.size();
  }
};