class Solution {
 public:
  int minMoves(vector<int>& nums, int limit) {
    int n = nums.size();
    vector<int> diff(2 * limit + 2);  // [2, 2 * limit]

    for (int i = 0; i + i < n; i++) {
      int A = nums[i];
      int B = nums[n - 1 - i];

      // 对于一个目标补x来说他的范围对于该数对的操作数影响如下
      // 1) [A+B, A+B]处于该范围内A和B都不需要修改，操作数为0
      // 2) [1+min(A, B), limit+max(A,B)]处于该范围内只要修改A或者B即可，
      //    操作数为1 3) 对于其他所有情况需要的操作数为2

      // 先假定对于范围内所有的补数x都需要该数对进行两次操作
      diff[2] += 2;
      diff[2 * limit + 1] -= 2;

      // 按照上面第二条，这种情况下我们只需要1次操作即可，所以该范围x所需操作减1
      diff[1 + min(A, B)] += -1;
      diff[limit + max(A, B) + 1] -= -1;

      // 第一条规则
      diff[A + B] += -1;
      diff[A + B + 1] -= -1;
    }

    int cur = 0;
    int ans = n;
    // 通过差分求前缀和，就是一个补数x对应的操作数
    for (int i = 2; i <= 2 * limit; i++) {
      cur += diff[i];
      if (cur < ans) {
        ans = cur;
      }
    }

    return ans;
  }
};