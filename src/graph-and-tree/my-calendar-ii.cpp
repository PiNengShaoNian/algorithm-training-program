class MyCalendarTwo {
 public:
  MyCalendarTwo() {}

  void update(int start, int end, int val, int l, int r, int idx) {
    if (r < start || l > end) {
      return;
    }

    if (start <= l && end >= r) {
      tree[idx].max += val;
      tree[idx].lazy += val;
    } else {
      int mid = (l + r) >> 1;
      update(start, end, val, l, mid, 2 * idx);
      update(start, end, val, mid + 1, r, 2 * idx + 1);
      tree[idx].max =
          tree[idx].lazy + max(tree[2 * idx].max, tree[2 * idx + 1].max);
    }
  }

  bool book(int start, int end) {
    update(start, end - 1, 1, 0, 1e9, 1);

    if (tree[1].max > 2) {
      update(start, end - 1, -1, 0, 1e9, 1);
      return false;
    }

    return true;
  }

 private:
  struct NodeVal {
    int max;
    int lazy;
  };
  unordered_map<int, NodeVal> tree;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */