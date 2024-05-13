struct Comp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    int d1 = a.second - a.first;
    int d2 = b.second - b.first;
    return (d1 / 2 < d2 / 2) || (d1 / 2 == d2 / 2 && a.first > b.first);
  }
};

class ExamRoom {
  int n;
  set<int> seats;
  priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

 public:
  ExamRoom(int n) : n(n) {}

  int seat() {
    if (seats.empty()) {
      seats.insert(0);
      return 0;
    }

    // 最左边到第一个有座位的位置的距离
    int left = *seats.begin();
    // 最后一个座位到最右边的距离
    int right = n - *seats.rbegin() - 1;
    while (seats.size() >= 2) {
      auto [l, r] = pq.top();
      if (seats.count(l) && seats.count(r) && *next(seats.find(l)) == r) {
        int d = r - l;
        if (d / 2 <= left || d / 2 < right) {
          break;
        }
        pq.pop();
        pq.push({l, l + d / 2});
        pq.push({l + d / 2, r});
        seats.insert(l + d / 2);
        return l + d / 2;
      }
      pq.pop();
    }
    if (right > left) {
      pq.push({*seats.rbegin(), n - 1});
      seats.insert(n - 1);
      return n - 1;
    } else {
      pq.push({0, *seats.begin()});
      seats.insert(0);
      return 0;
    }
  }

  void leave(int p) {
    if (p != *seats.begin() && p != *seats.rbegin()) {
      auto it = seats.find(p);
      pq.push({*prev(it), *next(it)});
    }
    seats.erase(p);
  }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */