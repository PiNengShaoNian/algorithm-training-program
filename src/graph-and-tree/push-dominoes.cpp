class Solution {
 public:
  string pushDominoes(string dominoes) {
    // 在t时刻一个向左偏斜的骨牌在t+1时刻会对它左边的骨牌施加一个向左的力
    int n = dominoes.size();
    // time[i] = x表示第i个骨牌能在第x时刻确定它的倒向
    vector<int> time(n, -1);
    // 该位置受到力的方向, 可能同时受到多个力的作用
    vector<string> force(n);
    queue<int> q;

    for (int i = 0; i < n; i++) {
      if (dominoes[i] != '.') {
        // 将在0时刻就能确定倒向的骨牌加入队列
        q.push(i);
        force[i].push_back(dominoes[i]);
        time[i] = 0;
      }
    }
    string ans(n, '.');
    while (q.size()) {
      int i = q.front();
      q.pop();

      // 只用更新只受到一个力的骨牌，同时受到两个力的不用更新比如"R.L",
      // 中间的.会受到两个力
      // "R...R"像这种字符串中最后一个字符R理论上也会受两个力但是不会被加入到队列中因为不满足time[ni]
      // = t + 1
      if (force[i].size() == 1) {
        char f = force[i][0];
        int ni = (f == 'L') ? (i - 1) : (i + 1);
        ans[i] = f;
        if (ni >= 0 && ni < n) {
          int t = time[i];
          if (time[ni] == -1) {
            time[ni] = t + 1;
            force[ni].push_back(f);
            q.push(ni);
          } else if (time[ni] == t + 1) {
            // 在t+1时刻已受到一个方向的力，说明这个位置会同时受到两个相反方向的力，不用将他加入队列
            force[ni].push_back(f);
          }
        }
      }
    }
    return ans;
  }
};

class Solution {
 public:
  string pushDominoes(string dominoes) {
    int n = dominoes.size(), i = 0;
    char left = 'L';
    /**
     * 如果两边的骨牌同向，那么这段连续的竖立骨牌会倒向同一方向。
     * 如果两边的骨牌相对，那么这段骨牌会向中间倒。
     * 如果两边的骨牌相反，那么这段骨牌会保持竖立。
     */
    while (i < n) {
      int j = i;
      while (j < n && dominoes[j] == '.') {
        j++;
      }
      char right = j < n ? dominoes[j] : 'R';
      if (left == right) {
        while (i < j) {
          dominoes[i++] = left;
        }
      } else if (left == 'R' && right == 'L') {
        int k = j - 1;
        while (i < k) {
          dominoes[i++] = 'R';
          dominoes[k--] = 'L';
        }
      }
      left = right;
      i = j + 1;
    }
    return dominoes;
  }
};