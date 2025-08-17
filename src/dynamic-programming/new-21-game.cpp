class Solution {
 public:
  // 未优化解法,O(k * maxPts)
  double new21Game1(int n, int k, int maxPts) {
    if (k == 0) {
      return 1.0;
    }
    vector<double> dp(k + maxPts);
    for (int i = k; i <= n && i < k + maxPts; i++) {
      dp[i] = 1.0;
    }

    // 从前往后推出答案
    for (int i = k - 1; i >= 0; i--) {
      for (int j = 1; j <= maxPts; j++) {
        dp[i] += dp[i + j] / maxPts;
      }
    }
    return dp[0];
  }

  double new21Game(int n, int k, int maxPts) {
    if (k == 0) return 1.0;
    // dp[x]假设初始时已经有x分，获胜的概率，所以dp[0]就是最终要求的答案
    vector<double> dp(maxPts + k, 0);

    // 最终可以获得的最大的分数为maxPts + k - 1(倒数第二轮是获得了k -
    // 1的分数，然后有选到了一个
    // maxPts的分数)。最终可以获得的最小分数为k(如果小于k的话，要一直抽取数字)
    // 所以对于 k <= i < maxPts + k，dp[i]为1即一定会获胜
    for (int i = k; i <= n && i < maxPts + k; ++i) {
      dp[i] = 1.0;
    }

    // 我们必须算先初始化dp[k-1]，当第一步就拥有了k - 1分时,只要抽取的时候
    // 抽取的分数小于等于n - k + 1我们都能获胜，由于我们最大只能抽取到分数
    // maxPts所以实际获胜的抽取范围为min(n - k + 1, maxPts)，由于抽取到
    // 每个分数的概率相同都是1 / maxPts所以dp[k - 1]就等于min(n - k + 1, maxPts)
    // / maxPts
    dp[k - 1] = 1.0 * min(n - k + 1, maxPts) / maxPts;
    // 如果 0 <= x <= k - 1
    // 通过上面的未优化解法可以发现dp[x] - dp[x + 1] = (dp[x + 1] - dp[x +
    // maxPts + 1]) / maxPts 所以dp[x] = dp[x + 1] - (dp[x + maxPts + 1] - dp[x
    // + 1]) / maxPts
    for (int i = k - 2; i >= 0; --i) {
      dp[i] = dp[i + 1] - (dp[i + maxPts + 1] - dp[i + 1]) / maxPts;
    }

    return dp[0];
  }
};

class Solution {
 public:
  double new21Game(int n, int k, int w) {
    vector<double> dp(k + w);
    double s = 0;
    for (int i = k; i < k + w; i++) {
      dp[i] = i <= n;
      s += dp[i];
    }

    for (int i = k - 1; i >= 0; i--) {
      dp[i] = s / w;
      s = s - dp[i + w] + dp[i];
    }
    return dp[0];
  }
};