class SegmentTree {
  vector<int> mx;

  void maintain(int o) { mx[o] = max(mx[o * 2], mx[o * 2 + 1]); }

  void build(const vector<int>& a, int o, int l, int r) {
    if (l == r) {
      mx[o] = a[l];
      return;
    }

    int mid = (l + r) / 2;
    build(a, o * 2, l, mid);
    build(a, o * 2 + 1, mid + 1, r);
    maintain(o);
  }

 public:
  SegmentTree(const vector<int>& a) {
    size_t n = a.size();
    mx.resize(2 << bit_width(n - 1));
    build(a, 1, 0, n - 1);
  }

  int findFirstAndUpdate(int o, int l, int r, int x) {
    if (mx[o] < x) {
      return -1;
    }

    if (l == r) {
      mx[o] = -1;
      return l;
    }

    int mid = (l + r) / 2;
    int i = findFirstAndUpdate(o * 2, l, mid, x);
    if (i < 0) {
      i = findFirstAndUpdate(o * 2 + 1, mid + 1, r, x);
    }
    maintain(o);
    return i;
  }
};

class Solution {
 public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    SegmentTree t(baskets);
    int n = baskets.size();
    int ans = 0;
    for (int fruit : fruits) {
      if (t.findFirstAndUpdate(1, 0, n - 1, fruit) == -1) {
        ans++;
      }
    }
    return ans;
  }
};