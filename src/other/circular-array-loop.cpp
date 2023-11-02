class Solution {
 public:
  bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    auto next = [&](int cur) {
      return ((cur + nums[cur]) % n + n) % n;  // 保证返回值在 [0,n) 中
    };

    for (int i = 0; i < n; i++) {
      if (!nums[i]) {
        continue;
      }
      int slow = i, fast = next(i);
      // while循环里面的判断同时保证了序列的方向和不会访问到已经访问过的节点
      while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
        if (slow == fast) {
          // 避免nums[i] = n * i这种情况
          if (slow != next(slow)) {
            return true;
          } else {
            break;
          }
        }
        slow = next(slow);
        fast = next(next(fast));
      }
      // 将已经访问过的节点设置为0
      int add = i;
      while (nums[add] * nums[next(add)] > 0) {
        int tmp = add;
        add = next(add);
        nums[tmp] = 0;
      }
    }
    return false;
  }
};