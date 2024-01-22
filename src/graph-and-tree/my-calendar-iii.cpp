class MyCalendarThree {
 public:
  MyCalendarThree() {}

  void update(int start, int end, int l, int r, int idx) {
    if (start > r || end < l) {
      return;
    }

    if (start <= l && r <= end) {
      tree[idx].max += 1;
      tree[idx].lazy += 1;
    } else {
      int mid = (l + r) >> 1;
      update(start, end, l, mid, idx * 2);
      update(start, end, mid + 1, r, idx * 2 + 1);
      tree[idx].max =
          tree[idx].lazy + max(tree[idx * 2].max, tree[idx * 2 + 1].max);
    }
  }

  int book(int startTime, int endTime) {
    update(startTime, endTime - 1, 0, 1e9, 1);

    return tree[1].max;
  }

 private:
  struct TreeNode {
    int max;
    int lazy;
  };
  unordered_map<int, TreeNode> tree;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */