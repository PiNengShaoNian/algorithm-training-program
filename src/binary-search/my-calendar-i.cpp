class MyCalendar {
  set<pair<int, int>> booked;

 public:
  MyCalendar() {}

  bool book(int start, int end) {
    auto it = booked.lower_bound({end, 0});
    if (it == booked.begin() || (--it)->second <= start) {
      booked.emplace(start, end);
      return true;
    }
    return false;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */