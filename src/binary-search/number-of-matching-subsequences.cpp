class Solution {
 public:
  int numMatchingSubseq(string s, vector<string> &words) {
    vector<vector<int>> pos(26);
    for (int i = 0; i < s.size(); i++) {
      pos[s[i] - 'a'].push_back(i);
    }

    int ans = words.size();
    for (auto &w : words) {
      if (w.size() > s.size()) {
        ans--;
        continue;
      }

      // word的当前字符c能在s中最靠前的位置
      int p = -1;
      for (char c : w) {
        auto &ps = pos[c - 'a'];
        auto it = upper_bound(ps.begin(), ps.end(), p);
        if (it == ps.end()) {
          ans--;
          break;
        }
        p = *it;
      }
    }

    return ans;
  }
};

class Solution {
 public:
  int numMatchingSubseq(string s, vector<string> &words) {
    vector<queue<pair<int, int>>> queues(26);
    for (int i = 0; i < words.size(); i++) {
      queues[words[i][0] - 'a'].push({i, 0});
    }

    int ans = 0;
    for (char c : s) {
      auto &q = queues[c - 'a'];
      int size = q.size();
      while (size--) {
        auto [i, j] = q.front();
        q.pop();

        j++;
        if (j == words[i].size()) {
          ans++;
        } else {
          queues[words[i][j] - 'a'].push({i, j});
        }
      }
    }
    return ans;
  }
};