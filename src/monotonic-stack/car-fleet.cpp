class Solution {
 public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    map<int, int> ps;
    int n = position.size();
    for (int i = 0; i < n; i++) {
      ps[position[i]] = speed[i];
    }
    // 单调递减栈
    stack<float> stk;
    int ans = 0;
    for (auto& [pos, spd] : ps) {
      // 如果time比栈顶的元素大说明他们俩能组成一个车队
      float time = float(target - pos) / spd;
      while (!stk.empty() && time >= stk.top()) {
        stk.pop();
      }
      stk.push(time);
    }

    return stk.size();
  }
};